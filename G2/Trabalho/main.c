#include <stdio.h>
#include "gera_codigo.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned char code[500];
    funcp funcLBS;
    int res;
    
    fp = fopen("progLBS.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo progLBS\n");
        return -1;
    }
    
    gera_codigo(fp, code, &funcLBS);
    /*if (funcLBS == NULL) {
        printf("Erro na geracao\n");
        fclose(fp); 
        return -1;
    }*/
    
    //res = (*funcLBS)(<argumento>);
    fclose(fp);
    return 0;
}
