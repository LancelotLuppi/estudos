#include <stdio.h>
#include <string.h>

void home() {
	printf("--------------------------------------------\n");
	printf("*   Por favor, digite o nome do arquivo    *\n");
	printf("*   que deseja contar as linhas, e nao se  *\n");
	printf("*   esqueca de colocar o .txt ao final     *\n");
	printf("--------------------------------------------\n");
}

FILE* abrir_arquivo_por_nome() {
	char name_file[100];
	scanf("%s", &name_file);
	return fopen(name_file, "r");
}

int verificar_arquivo_presente(FILE *file) {
	if(file == NULL) {
    	printf("Erro ao abrir arquivo");
    	return -1;
	}
}

void contador_linhas(FILE *file, int* linhas) {
	char texto[100];
	while(!feof(file)) {
		fgets(texto, 100, file);
		if(strlen(texto) < 99) {
			(*linhas)++;
		}
	}
}

int main() {
	int linhas = 0;
	FILE *file;

	home();

 	file = abrir_arquivo_por_nome();
    verificar_arquivo_presente(file);
	contador_linhas(file, &linhas);
	
	printf("Quantidade de linhas: %d", linhas);
	
    fclose(file);
    return 0;
}

