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

    //insere_fim(&list, 8);
    insere_inicio(&list, 10);
    insere_ordenado(&list, 3);
    insere_fim(&list, 20);
    insere_inicio(&list, 7);
    insere_ordenado(&list, 50);
    insere_ordenado(&list, 80);
    insere_ordenado(&list, 2);
    insere_ordenado(&list, 12);
    imprimir(list);
}
