#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("dados.dat", "wb+");

    if(!file) {
        printf("Nao foi possivel abrir o arquivo");
        return -1;
    }

    int dado;
    while(fread(&dado, sizeof(int), 1, file) != 0) {

        if(dado<=1000 && dado>=-1000) {
            continue;
        }
        if(dado < -1000) {
            dado = -1000;
        } else {
            dado = 1000;
        }

        fseek(file, -(long)sifeof(int), SEEK_CUR);
        fwrite(&dado, sizeof(int), 1, file);
    }
    fclose(file);
    return 0;
}