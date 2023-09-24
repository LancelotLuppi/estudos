#include <stdio.h>

#define ESCRITA = "wb";
#define LEITURA = "rb";
#define LEITURA_E_ESCRITA = "rb+";
#define LEITURA_E_ESCRITA_APAGANDO = "wb+";
#define LEITURA_E_ESCRITA_AO_FINAL = "ab+";

void escrever_binario(FILE* file) {
    char texto[100];
    printf("Escreva a informacao que deseja salvar no arquivo: ");
    scanf("%s ", texto);
    fwrite(texto, sizeof(texto), 1, file);
}

FILE* abrir_arquivo_por_nome() {
    printf("Digite o nome do arquivo com .txt no final: ");
    char file_name[100];
    scanf("%s", &file_name);
    return fopen(file_name, "wb+"); 
}


int main() {
    FILE *file = abrir_arquivo_por_nome();

    if(!file) {
        printf("Erro ao abrir arquivo");
        return -1;
    }

    escrever_binario(file);

    fclose(file);
    return 0;
}
