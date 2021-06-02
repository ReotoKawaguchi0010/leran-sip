#include <stdio.h>
#include "g711dec.h"


int main(){
    bin_out(12);

    int t;
    t = 12;
    printf("%p\n", &t);
    t = 13;
    printf("%p\n", &t);


    t = (t == 0) ? 1: 2;

    return 0;
}

void bin_out(int value){
    int i;
    for(i=0x8000; i>0; i >>= 1){
        printf("[");
        printf("value:{%d} ", value);
        printf("i:{%d} ", i);
        printf("and:{%d}", value&i);
        printf("]\n");
    }
    printf("\n");

    for(i=0x8000; i>0; i >>= 1){
        if(value & i){
            printf("1");
        }else{
            printf("0");
        }
    }
    printf("\n");
}

short g711decode(unsigned char ulow_sample){
    short audio_sample;
    int t;

    ulow_sample = ~ulow_sample;
    t = ((ulow_sample & 0x0f) << 3) + BIAS;
    t <<= (ulow_sample & 0x70) >> 4;
    if(ulow_sample & 0x80){
        audio_sample = BIAS - t;
    }else{
        audio_sample = t - BIAS;
    }

    return audio_sample;

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