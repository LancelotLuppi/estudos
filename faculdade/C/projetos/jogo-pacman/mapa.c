#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mapa.h"

void copiar_mapa(Mapa* destino, Mapa* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocar_memoria_mapa(destino);

    for(int i=0; i<origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void encontra_posicao(Mapa* m, Posicao* p, char c) {
    for(int i=0; i<m->linhas; i++) {
        for(int j=0; j<m->colunas; j++) {
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

void mover_personagem(Mapa* m, int origem_x, int origem_y, int destino_x, int destino_y) {
    char personagem = m->matriz[origem_x][origem_y];
    m->matriz[destino_x][destino_y] = personagem;
    m->matriz[origem_x][origem_y] = VAZIO;
}

int verificar_movimento_invalido(Mapa* m, int x, int y) {
    return x >= m->linhas || y >= m->colunas || m->matriz[x][y] != VAZIO;
}

void libera_memoria_mapa(Mapa* m) {
    for(int i=0; i< m->linhas; i++) {
        free(m->matriz[i]); // ---------> Liberamos o espaço da memória de cada linha representando o mapa;
    }
    free(m->matriz); // ----------------> Liberamos o espaço da memória do ponteiro de ponteiros do mapa;
}

void alocar_memoria_mapa(Mapa* m) {
    m->matriz = malloc(sizeof(char*) * m->linhas); // --> Alocamos espaço na memória para um ponteiro de ponteiros de inteiro, com 5 posições;

    for(int i=0; i< m->linhas; i++) { // -------------> Percorre cada pointer de inteiros dentro do pointer de pointers que criamos;
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1)); // -> Para cada execução, alocamos o espaço para 10 posições de int em cada pointer percorrido;
    }
}

void ler_mapa(Mapa* m) {
    FILE* f;
    f = fopen("mapa.txt", "r");

    if(f ==0) {
        printf("Erro ao ler o arquivo");
        exit(1);
    }

    fscanf(f, "%d %d", &m->linhas, &m->colunas);

    alocar_memoria_mapa(m);

    for(int i=0; i< m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void imprime_mapa(Mapa* m) {
    for(int i=0; i< m->linhas; i++) {
        printf("%s\n", m->matriz[i]);
    }
}