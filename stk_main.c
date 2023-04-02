#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>

// サウンドが終了したときに呼び出されるコールバックを定義します
// 再生中。プレイ後にメモリを解放する必要がある場合に便利です。
static void MyCompletionCallback (
        SystemSoundID  mySSID,
        void * myURLRef
)
{
    AudioServicesDisposeSystemSoundID (mySSID);
    CFRelease (myURLRef);
    CFRunLoopStop (CFRunLoopGetCurrent());
}


int main (int argc, const char * argv[])
{
    // Set up the pieces needed to play a sound.
    SystemSoundID    mySSID;
    CFURLRef        myURLRef;
    myURLRef = CFURLCreateWithFileSystemPath(
            kCFAllocatorDefault,
            CFSTR ("../../ComedyHorns.aif"),
            kCFURLPOSIXPathStyle,
            FALSE
    );

    // create a system sound ID to represent the sound file
    OSStatus error = AudioServicesCreateSystemSoundID (myURLRef, &mySSID);

    // Register the sound completion callback.
    // Again, useful when you need to free memory after playing.
    AudioServicesAddSystemSoundCompletion(
            mySSID,
            NULL,
            NULL,
            MyCompletionCallback,
            (void *) myURLRef
    );

    // Play the sound file.
    AudioServicesPlaySystemSound(mySSID);

    // Invoke a run loop on the current thread to keep the application
    // running long enough for the sound to play; the sound completion
    // callback later stops this run loop.
    CFRunLoopRun();
    return 0;
}
