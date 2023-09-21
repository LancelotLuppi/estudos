#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **queue, int num) {
    Node *aux, *newNode = malloc(sizeof(Node));
    if(newNode) {
        newNode->data = num;
        newNode->next = NULL;
        if(*queue == NULL) {
            *queue = newNode;
        }   
        else {
            aux = *queue;
            while(aux->next)
                aux = aux->next;
            aux->next = newNode;
        }
    } else {
        printf("\n Error allocating memory \n");
    }
}

void removeQ(Node **queue) {
    Node *removed = NULL;
    Node *aux = malloc(sizeof(Node));

    if(*queue) {
        removed = *queue;
        *queue = removed->next;
    } else {
        printf("\n Empty queue \n");
    }
}

void printQ(Node *list) {
    printf("\n List: ");
    while(list) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n\n");
}

int main() {
    Node *queue = NULL;

    insert(&queue, 10);
    insert(&queue, 13);
    insert(&queue, 12);
    removeQ(&queue);
    printQ(queue);
}
