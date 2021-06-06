#include <stdio.h>

int main() {
    int test;
    test = 0b1111;

    long bit;
    bit = test ^ 0xff5;
    printf("%lx\n", bit);

    int bit_num = 0x0f;
    printf("%08d\n", bit_num);
    printf("%08d\n", bit_num >> 1);
    printf("%08d\n", bit_num << 1);
    return 0;
}