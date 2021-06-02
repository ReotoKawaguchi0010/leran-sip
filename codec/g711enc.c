#include <stdio.h>
#include "g711enc.h"

int main() {
    int i;
    unsigned char mu_val;
    short a_smp[8] = {
            -1,
            139,
            443,
            1083,
            -2461,
            -5373,
            -11421,
            -24061,
    };

    for(i=0; i<8;i++){
        mu_val = g711encode(a_smp[i]);
        disp_c(mu_val);
        printf("\n");
    }
    return 0;
}

unsigned char g711encode(short audio_sample){
    int i;
    int mask;
    int range;
    unsigned char mulaw_val;


    if(audio_sample > 0 && audio_sample > CLIP) audio_sample = CLIP;
    if(audio_sample < 0 && audio_sample < -CLIP) audio_sample = -CLIP;
    if(audio_sample < 0){
        mask = 0x7f;
        audio_sample = -audio_sample;
    }else{
        mask = 0xff;
    }

    audio_sample += BIAS;
    i = 7;
    for(range = 0x4000; range >= 0x80; range >>= 1){
        if(range & audio_sample) break;
        i--;
    }
    mulaw_val = (i << 4) + ((audio_sample >> (i+3)) & 0x0f);
    disp_c(mulaw_val);
    return mulaw_val;
}

void disp_s(short value){
    int i;
    printf("\t");
    for(i=0x8000; i>0; i >>= 1){
        if(value & i){
            printf("1");
        }else{
            printf("0");
        }
    }
}

void disp_c(unsigned char value){
    int i;
    printf("\t");
    for(i=0x80; i>0; i >>= 1){
        if(value & i){
            printf("1");
        }else{
            printf("0");
        }
    }
}
