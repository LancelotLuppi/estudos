#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* abrir_arquivo() {
    printf("Digite o nome do arquivo com .txt no final: ");
    char file_name[50];
    scanf("%s", &file_name);
    return fopen(file_name, "r");
}

int existe_ocorrencia(char *texto, char *palavra, int id) {
    int i, j = 0;

    for(i = id; i<strlen(texto); i++) {
        if(texto[i] == palavra[i]) {
            j++;
        } else {
            j = 0;
        }
        if(j == strlen(palavra)) {
            return i;
        }
    }
    return -1;
}

int main() {

    FILE *file;
    file = abrir_arquivo();

    if(!file) {
        printf("erro ao abrir arquivo");
        return -1;
    }

    printf("Digite a palavra que deseja buscar: ");
    char palavra[50];
    scanf("%s", palavra);
    char texto[500];
    int indice = 0, quantidade = 0;

    while(!feof(file)) {
        fgets(texto, 500, file);

        printf("%s\n", texto);

        do {
            indice = existe_ocorrencia(texto, palavra, indice);
            if(indice != -1) {
                quantidade++;
            }
        } while(indice != -1);
        printf("%d\n", quantidade);
    }
    printf("Quantidade de ocorrencias da palavra %s: %d vezes", palavra, quantidade);
}
