#include <stdio.h>

unsigned char switch_byte(unsigned char x) {
    return ((x & 0x0F) << 4) | (x >> 4);
}


int main() {
    unsigned char x = 0xAB;

    printf("%02X -> %02X\n", x, switch_byte(x));

    return 0;
}