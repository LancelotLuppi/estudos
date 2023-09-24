#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insere_inicio(Node **list, int num) {
    Node *novo = malloc(sizeof(Node));

    if(novo) {
        novo->data = num;
        novo->next = *list;
        *list = novo;
    } else {
        printf("Nao foi possivel alocar a memoria.");
    }
}

void insere_fim(Node **list, int num) {
    Node *aux,*novo = malloc(sizeof(Node));

    if(novo) {
        novo->data = num;
        novo->next = NULL;

        if(*list == NULL) {
            *list = novo;
        } else {
            aux = *list;
            while(aux->next) {
                aux = aux->next;
            }
            aux->next = novo;
        }
    } else {
        printf("Nao foi possivel alocar a memoria.");
    }
}

void insere_meio(Node **list, int num, int ant) {
    Node *aux, *novo = malloc(sizeof(Node));

    if(novo) {
        novo->data = num;
        
        if(*list == NULL) {
            novo->next = NULL;
            *list = novo;
        } else {
            aux = *list;
            while(aux->data != ant && aux->next) {
                aux = aux->next;
            }
            novo->next = aux->next;
            aux->next = novo;
        }
    } else {
        printf("Nao foi possivel alocar a memoria.");
    }
}

void insere_ordenado(Node **list, int num) {
    Node *aux, *novo = malloc(sizeof(Node));

	if(novo) {
		novo->data = num;
		
		if(*list == NULL) {
			novo->next = NULL;
			*list = novo;
		} else if (novo->data < (*list)->data) {
			novo->next = *list;
			*list = novo;
		} else {
			aux = *list;
			while(aux->next && novo->data > aux->next->data) {
				aux = aux->next;
			}
			novo->next = aux->next;
			aux->next = novo;
		}
	}
}

void conta_repetidos(Node **list) {
	Node *aux, *verificacao = malloc(sizeof(Node));
	aux = *list;
	int verificados[100];
	int inseridos = 0;
	
	while(aux->next) {
		int ocorrencia = 1;
		int valorVerificado = aux->data;
		
		verificacao = aux;
		while(verificacao->next) {	
			verificacao = verificacao->next;
			if(verificacao->data == valorVerificado) {
				ocorrencia++;
			}
			if(verificacao->next == NULL) {
				int i;
				int jaExibido = 0;
				for(i = 0; i<inseridos; i++) {
					if(verificados[i] == valorVerificado) {
						jaExibido = 1;
					}
				}
				if((jaExibido != 1 || inseridos == 0) && ocorrencia > 1) {
					printf("\nO valor %d apareceu %d vezes.\n\n", valorVerificado, ocorrencia);
					verificados[inseridos] = valorVerificado;
					inseridos++;
				}
			}
		}
		aux = aux->next;
	}
}

void remocao_repetido(Node **list) {
	Node *aux, *verificacao, *remover = malloc(sizeof(Node));
	aux = *list;
	
	if(*list) {
		aux = *list;
		while(aux->next) {
			int valor_verificado = aux->data;
			verificacao = aux;
			while(verificacao->next) {
				if(verificacao->next->data == valor_verificado) {
					remover = verificacao->next;
					verificacao->next = remover->next;
				}
				verificacao = verificacao->next;
			}
			aux = aux->next;
		}
	}
	
	while(aux->next) {
		int ocorrencia = 1;
		int valorVerificado = aux->data;
		
		aux = aux->next;
	}
}

void imprimir(Node *list) {
    printf("\nLista: ");
    while(list) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n\n");
}

int main() {
    Node *list = NULL;
    int posicoes[5];

    insere_inicio(&list, 10);
    insere_inicio(&list, 7);
    insere_inicio(&list, 10);
    insere_inicio(&list, 7);
    insere_inicio(&list, 6);
    insere_fim(&list, 12);
    
    imprimir(list);
    
    conta_repetidos(&list);
    
    printf("\n\nRemovendo valores repetidos: \n");
    remocao_repetido(&list);
    
    imprimir(list);
}
