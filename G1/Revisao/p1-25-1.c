/*

REVISÃO PARA P1

P1 2025.1

*/


// Questão 1 


#include <stdio.h>

void dump (void *p, int n) {
unsigned char *p1 = (unsigned char *) p;
while (n--) {
printf("%p - %02X\n", p1, *p1);
p1++;
}
}

struct Estrutura {
char c;
int *p;
int i;
short s;
};

int main(void) {
struct Estrutura variavel;
variavel.c = 'F';
variavel.p = &variavel.i;
variavel.i = -25;
variavel.s = 47;
dump(&s, sizeof(struct Estrutura));
return 0;
}

// https://chatgpt.com/s/t_6ac1c00bef248191a6372dc972cfc1fc