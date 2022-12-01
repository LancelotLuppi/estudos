#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j, qnt_inputs;
    int lista_iniciais = 0;

    scanf("%d", &qnt_inputs);
    int *lista_palavras = (int*)calloc(qnt_inputs, sizeof(int));
    char palavra[1000000];

    for(i=0; i<qnt_inputs; i++) {
        scanf("%s", palavra);
        lista_iniciais |= (1<<(palavra[0]-'A'));
        int let=0;

        for(j=0; palavra[j]; j++) {
            let |= (1<<(palavra[j]-'A'));
        }
        lista_palavras[i]=let;
    }
    for(i=0; i<N; i++) {
        if((lista_palavras[i]&lista_iniciais)==lista_palavras[i]) {
            break;
        }
    }
    printf("%c\n", i<qnt_inputs ? 'Y' : 'N');
    return 0;
}