typedef struct {
    char** matriz;
    int linhas;
    int colunas;
}Mapa;

typedef struct {
    int x;
    int y;
}Posicao;

void libera_memoria_mapa(Mapa* m);
void ler_mapa(Mapa* m);
void alocar_memoria_mapa(Mapa* m);
void imprime_mapa(Mapa* m);
void encontra_posicao(Mapa* m, Posicao* p, char c);