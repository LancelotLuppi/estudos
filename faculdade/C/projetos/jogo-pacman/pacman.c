#include<stdio.h>
#include<stdlib.h>
#include "pacman.h"
#include "mapa.h"

Mapa m;
Posicao heroi;




int acabou() {
    return 0;
}

void mover(char direcao) {

    if(direcao != 'a' &&
       direcao != 'w' &&
       direcao != 's' &&
       direcao != 'd') {
        return;
    }

    int prox_x = heroi.x;
    int prox_y = heroi.y;

    switch (direcao) {
        case 'a':
            prox_y--;
            break;
        case 'w':
            prox_x--;
            break;
        case 's':
            prox_x++;
            break;
        case 'd':
            prox_y++;
            break;
    }

    if(prox_x >= m.linhas || prox_y >= m.colunas || m.matriz[prox_x][prox_y] != '.') {
        return;
    }

    m.matriz[prox_x][prox_y] = '@';
    m.matriz[heroi.x][heroi.y] = '.';
    heroi.x = prox_x;
    heroi.y = prox_y;
}

int main() {

    ler_mapa(&m);
    encontra_posicao(&m, &heroi, '@');

    do {

        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        mover(comando);
    } while(!acabou());

    

    libera_memoria_mapa(&m);
}