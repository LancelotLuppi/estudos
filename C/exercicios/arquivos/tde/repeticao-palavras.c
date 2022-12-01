#include <stdio.h>

FILE* abrir_arquivo() {
    printf("Digite o nome do arquivo com .txt no final: ");
    char file_name[100];
    scanf("%s", &file_name);
    return fopen(file_name, "r");
}

int main() {

    FILE *file;
    file = abrir_arquivo();
    int i, k, tam_palavra_escolhida, char_igual, qnt_repeticao;

    printf("\n-----------------------------------------\n");

    printf("Digite a palavra que deseja buscar: ");
    char palavra[50];
    scanf("%s ", &palavra);

    char str_arquivo[100];

    if(!file) {
    	printf("Falha ao abrir o arquivo");
    	return 1;
	}
	
    tam_palavra_escolhida = sizeof(palavra);
    qnt_repeticao = 0;
    char_igual = 0;
    k = 0;
    
	while(!feof(file)) {
		fgets(str_arquivo, 100, file);
		
		i = 0;
		
		while(i<sizeof(str_arquivo)) {
			
			if((char_igual == 0 && str_arquivo[i] == ' ') || (str_arquivo[i] == palavra[k])) {
       	    	char_igual++;
        	    k++;
        	} else if(char_igual > 1 && str_arquivo[i] != ' ') {
        	    k = 0;
        	    char_igual = 0;
        	}

       		if(char_igual == tam_palavra_escolhida && str_arquivo[i] == ' '){
        	    char_igual++;
        	}


        	if(char_igual == tam_palavra_escolhida+1) {
            	qnt_repeticao++;
        	}

        	i++;
		}
    }
    printf("Quantidade de vezes repetida: %d", qnt_repeticao);

	fclose(file);
    return 0;
}
