#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Date;

Date separarData(char str_data[]) {
    Date data;
    data.dia=0;
    data.mes=0;
    data.ano=0;

    const char split[2] = "/";
    char *token;

    token = strtok(str_data, split);
    while(token != NULL) {
        if(data.dia == 0) {
            data.dia = atoi(token);
        } else if(data.mes == 0) {
            data.mes = atoi(token);
        } else {
            data.ano = atoi(token);
        }
        token = strtok(NULL, split);
    }

    return data;
}


int main() {
    char str[] = "08//12/2003";
    Date meu_dia = separarData(str);

    printf("%d", meu_dia.dia);

    return 0;
}