#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "pacman.h"
#include "mapa.h"

Mapa m;
Posicao heroi;

int direcao_fantasma(int x_atual, int y_atual, int* x_destino, int* y_destino) {
    int opcoes[4][2] = {
        { x_atual, y_atual + 1 },
        { x_atual + 1, y_atual },
        { x_atual, y_atual - 1 },
        { x_atual - 1, y_atual }
    };

    srand(time(0));
    for(int i=0; i<10; i++) {
        int posicao = rand() % 4;
        if(!verificar_movimento_invalido(&m, opcoes[posicao][0], opcoes[posicao][1])) {
            *x_destino = opcoes[posicao][0];
            *y_destino = opcoes[posicao][1];

            return 1;
        }
    }

    return 0;
}

void fantasmas() {
    Mapa copia;

    copiar_mapa(&copia, &m);

    for(int i = 0; i < m.linhas; i++) {
        for(int j = 0; j < m.colunas; j++) {

            if(copia.matriz[i][j] == FANTASMA) {

                int x_destino;
                int y_destino;
                int encontrou = direcao_fantasma(i, j, &x_destino, &y_destino);

                if(encontrou) {
                    mover_personagem(&m, i, j, i, j+1);
                }
            }

        }
    }
    libera_memoria_mapa(&copia);
}


int acabou() {
    return 0;
}

int direcao_valida(char direcao) {
    return direcao == ESQUERDA ||
       direcao == CIMA ||
       direcao == BAIXO ||
       direcao == DIREITA;
}

void mover(char direcao) {

    if(!direcao_valida(direcao)) {
        return;
    }

    int prox_x = heroi.x;
    int prox_y = heroi.y;

    switch (direcao) {
        case ESQUERDA:
            prox_y--;
            break;
        case CIMA:
            prox_x--;
            break;
        case BAIXO:
            prox_x++;
            break;
        case DIREITA:
            prox_y++;
            break;
    }

    if(verificar_movimento_invalido(&m, prox_x, prox_y)) {
        return;
    }

    mover_personagem(&m, heroi.x, heroi.y, prox_x, prox_y);
    heroi.x = prox_x;
    heroi.y = prox_y;

}

int main() {

    ler_mapa(&m);
    encontra_posicao(&m, &heroi, HEROI);

    do {

        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        mover(comando);
        fantasmas();

    } while(!acabou());

    

    libera_memoria_mapa(&m);
}