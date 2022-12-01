#include <stdio.h>

FILE* abrir_arquivo() {
    char file_name[100];
    scanf("%s", &file_name);
    return fopen(file_name, "r");
}

int verificar_arquivo_presente(FILE *file) {
	if(file == NULL) {
    	printf("Erro ao abrir arquivo");
    	return -1;
	}
}

long retornar_tamanho_arquivo(FILE *file) {
    fseek(file, 0, SEEK_END);
    return ftell(file);
}

int main() {

    FILE *file;
    
    file = abrir_arquivo();
	verificar_arquivo_presente(file);

    long posicao = retornar_tamanho_arquivo(file);

    printf("O seu arquivo tem %ld bytes!", posicao);

	fclose(file);
    return 0;
}
