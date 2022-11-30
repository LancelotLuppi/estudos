#include <stdio.h>
#include <string.h>

void imprimir_cabecalho() {
    printf("*********************\n");
    printf("*   Jogo da Forca   *\n");
    printf("*********************\n\n");
}

int verificar_chutes(char letra, char chutes[], int tentativas) {
    int achou = 0;
    for(int j = 0; j<tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void capturar_chute(char chutes[], int* tentativas) {
    char chute;
        scanf(" %c", &chute);   /* O espaço antes do %c indica que
                                 * o ENTER no final da digitação 
                                 * deve ser ignorado no scanf,
                                 * evitando ficar no buffer de
                                 * memória do programa
                                 */

        chutes[(*tentativas)] = chute;
        (*tentativas)++;
}

void imprimir_forca(char palavra_secreta[], char chutes[], int tentativas) {
    for(int i = 0; i < strlen(palavra_secreta); i++) {

            int achou = verificar_chutes(palavra_secreta[i], chutes, tentativas);

            if(achou) {
                printf("%c ", palavra_secreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n\n");
}

void escolhe_palavra(char palavra_secreta[]) {
    sprintf(palavra_secreta, "CACHORRO");
}

int main() {
    char palavra_secreta[20];
    escolhe_palavra(palavra_secreta);

    int acertou = 0;
    int enforcou = 0;
    char chutes[26];
    int tentativas = 0;

    imprimir_cabecalho();

    do {

        imprimir_forca(palavra_secreta, chutes, tentativas);
        capturar_chute(chutes, &tentativas);
        

    } while(!acertou && !enforcou); // !0 => 1 :: !1 => 0 :: Condição 'não && não'

    printf("%s\n", palavra_secreta);

    return 0;
}