#include <stdio.h>
#include <string.h>

int main() {
    char nome[52];
    char data_atual[12];
    char data_nascimento[12];

    int dia_atual=0, mes_atual=0, ano_atual=0, dia_nascimento=0, mes_nascimento=0, ano_nascimento=0, idade;

    scanf("%s", nome);
    
    scanf("%s", data_atual);
    char * token = strtok(data_atual, "/");
    while(token != NULL) {
        if(dia_atual == 0) {
            dia_atual = atoi(token);
        } else if(mes_atual == 0) {
            mes_atual = atoi(token);
        } else if(ano_atual == 0) {
            ano_atual = atoi(token);
        }
        token = strtok(NULL, "/");
    }

    scanf("%s", data_nascimento);
    token = strtok(data_nascimento, "/");
    while(token != NULL) {
        if(dia_nascimento == 0) {
            dia_nascimento = atoi(token);
        } else if(mes_nascimento == 0) {
            mes_nascimento = atoi(token);
        } else if(ano_atual == 0) {
            ano_nascimento = atoi(token);
        }
        token = strtok(NULL, "/");
    }

    idade = ano_atual - ano_nascimento;

    if(mes_atual == mes_nascimento && dia_atual == dia_nascimento) {
        printf("Feliz aniversario!\n");
    }
    if((mes_atual < mes_nascimento) || (mes_atual == mes_nascimento && data_atual < data_nascimento)) {
        idade--;
    }

    printf("Voce tem %d anos %s.\n", idade, nome);
}