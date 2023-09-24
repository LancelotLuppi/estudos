#include <stdio.h>
#include <stdlib.h>

struct Cliente {
    char nome[50];
    float saldo;
} cliente;

int main() {

    FILE *arqin = fopen("entrada.dat", "rb");
    FILE *arqout = fopen("saida.txt", "wt");

    if(!(arqout && arqin)) {
        printf("Erro ao abrir arquivos");
        return -1;
    }

    while(fread(&cliente, sizeof(struct Cliente), 1, arqin) != 0) {
        if(cliente.saldo>=10) {
            fprintf(arqout, "%s %f\n", cliente.nome, cliente.saldo);
        }
    }
    fclose(arqin);
    fclose(arqout);
    return 0;
}