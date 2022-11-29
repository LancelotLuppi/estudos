#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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
int verificar_movimento_invalido(Mapa* m, int x, int y);
void mover_personagem(Mapa* m, int origem_x, int origem_y, int destino_x, int destino_y);
void copiar_mapa(Mapa* destino, Mapa* origem);