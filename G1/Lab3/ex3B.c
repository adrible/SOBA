#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n) {
    return (unsigned char)((x << n) | (x >> (8 - n)));
}

int main() {
    unsigned char x = 0x61;

    printf("rotate 1: %02x\n", rotate_left(x, 1));
    printf("rotate 2: %02x\n", rotate_left(x, 2));
    printf("rotate 7: %02x\n", rotate_left(x, 7));

    return 0;
}