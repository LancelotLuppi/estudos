#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carta {
    int valor;
    char naipe[10];
} Carta;

*Carta insere_carta_fim(Carta novaCarta, Carta cartas[]) {
	Carta novaLista[9];
    int i;
    for(i=0; i<9; i++) {
        if(!strlen(cartas[i].naipe)) {
            novaLista[i] = novaCarta;
        } else {
        	novaLista[i] = cartas[i];
		}
    }
    return novaLista;
}


int main() {
    int i;
    Carta listaCartas[9];

    Carta carta;
    carta.valor = 12;
    strcpy(carta.naipe, "espada");

    Carta novaLista[] = insere_carta_fim(carta, listaCartas);

    for(i=0; i<9; i++) {
    	if(!strlen(novaLista[i].naipe)) {
    		printf("Carta n%d------\n", i+1);
        	printf("Valor: %d\n", listaCartas[i].valor);
        	printf("Naipe: %d\n", listaCartas[i].naipe);
        	printf("\n");
		}
    }
}
