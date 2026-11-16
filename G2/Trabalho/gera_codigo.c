#include <stdio.h>
#include <stdlib.h>
#include "gera_codigo.h"

void gera_codigo (FILE *f, unsigned char code[], funcp *entry) {
  int pos = 0;
  int tipo;

  while ((tipo = fgetc(f)) != EOF) {
    switch (tipo) {

        case 'f': {
            char c0;

            if (fscanf(f, "unction%c", &c0) != 1) {
                printf("erro ao ler o comando de function\n");
                exit(1);
            }

            printf("function\n");
            break;
        }

        case 'e': {
            if (fgetc(f) != 'n' || fgetc(f) != 'd') {
                printf("erro ao ler o comando de end\n");
                exit(1);
            }

            printf("end\n");
            break;
        }

        case 'r': {
            int idx0;
            char var0;

            if (fscanf(f, "et %c%d", &var0, &idx0) != 2) {
                printf("erro ao ler o comando de retorno incondicional\n");
                exit(1);
            }

            printf("ret %c%d\n", var0, idx0);
            break;
        }

        case 'z': {
            int idx0, idx1;
            char var0, var1;

            if (fscanf(f, "ret %c%d %c%d",
                       &var0, &idx0, &var1, &idx1) != 4) {
                printf("erro ao ler o comando de retorno condicional\n");
                exit(1);
            }

            printf("zret %c%d %c%d\n", var0, idx0, var1, idx1);
            break;
        }

        case 'v': {
            int idx0;
            char var0 = tipo, c0;

            if (fscanf(f, "%d = %c", &idx0, &c0) != 2) {
                printf("erro ao ler o comando de atribuicao\n");
                exit(1);
            }

            if (c0 == 'c') { // call
              int numfunc, idx1;
              char var1;
              if (fscanf(f, "all %d %c%d\n", &numfunc, &var1, &idx1) != 3) {
                printf("erro ao ler o comando de atribuicao");
                exit(1);
              }
              
              printf("%c%d = call %d %c%d\n",var0, idx0, numfunc, var1, idx1);

            }
            else { // op aritmetica
              int idx1, idx2;
              char var1 = c0, var2, op;
              if (fscanf(f, "%d %c %c%d", &idx1, &op, &var2, &idx2) != 4) {
                printf("erro ao ler o comando de atribuicao\n");
                exit(1);
              }
              printf("%c%d = %c%d %c %c%d\n", var0, idx0, var1, idx1, op, var2, idx2);
              
            } 
            break;
        } 
    }
    fscanf(f, " ");
  }
  
}