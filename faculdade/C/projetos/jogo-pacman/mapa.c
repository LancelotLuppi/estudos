#include <stdlib.h>
#include <stdio.h>
#include "mapa.h"

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