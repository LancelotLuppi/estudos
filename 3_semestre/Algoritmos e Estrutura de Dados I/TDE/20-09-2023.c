#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef enum { false, true } bool;

void printList(Node* list) {
    printf("\n List: ");
    while (list) {
        printf("%c ", list->data);
        list = list->next;
    }
}

Node* push(Node** stack, char val) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode) {
        newNode->data = val;
        newNode->next = *stack;
        *stack = newNode;
    } else {
        printf("\n Error allocating memory. \n");
    }
    return NULL;
}

Node* pop(Node** stack) {
    if (*stack != NULL) {
        Node* remove = *stack;
        *stack = remove->next;
        return remove;
    } else {
        printf("\n Empty stack. \n");
    }
    return NULL;
}

void enqueue(Node** queue, char val) {
    Node* aux, *newNode = malloc(sizeof(Node));
    if (newNode) {
        newNode->data = val;
        newNode->next = NULL;
        if (*queue == NULL) {
            *queue = newNode;
        } else {
            aux = *queue;
            while (aux->next)
                aux = aux->next;
            aux->next = newNode;
        }
    } else {
        printf("\n Error allocating memory \n");
    }
}

Node* dequeue(Node** queue) {
    Node* removed = NULL;
    Node* aux = malloc(sizeof(Node));

    if (*queue) {
        removed = *queue;
        *queue = removed->next;
        return removed;
    } else {
        printf("\n Empty queue \n");
    }
    return NULL;
}

void appendToList(Node** list, char val) {
    Node* aux, *newNode = malloc(sizeof(Node));
    if (newNode) {
        newNode->data = val;
        newNode->next = NULL;

        if (*list == NULL) {
            *list = newNode;
        } else {
            aux = *list;
            while (aux->next) {
                aux = aux->next;
            }
            aux->next = newNode;
        }
    } else {
        printf("Unable to allocate memory.");
    }
}

void readString(Node** stack, Node** queue, bool* isDigit) {
    char input[256]; // Tamanho arbitr�rio para a entrada

    printf("\n Informe uma lista de caracteres alternando entre letras e numeros, separados por espacos em branco:\n");
    printf("\n O ultimo caractere deve ser do mesmo tipo que o primeiro.\n");
    printf("\n> ");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, " ");
    *isDigit = isdigit(token[0]);

    while (token != NULL) {
        int length = strlen(token);
        int i;
        for (i = 0; i < length; i++) {
            if (isspace(token[i])) {
                continue;
            }

            if (isdigit(token[i])) {
                push(stack, token[i]);
            } else {
                enqueue(queue, token[i]);
            }
        }
        token = strtok(NULL, " ");
    }
}

void buildList(Node** list, Node** queue, Node** stack, bool isDigit) {
    Node* newNode = malloc(sizeof(Node));

    if (isDigit) {
        newNode = pop(stack);
        appendToList(list, newNode->data);
    }
    newNode = dequeue(queue);
    appendToList(list, newNode->data);

    while (true) {
        if (*stack != NULL) {
            newNode = pop(stack);
            appendToList(list, newNode->data);
        }
        if (*queue != NULL) {
            newNode = dequeue(queue);
            appendToList(list, newNode->data);
        }
        if (*stack == NULL && *queue == NULL) {
            break;
        }
    }
}

int main() {
    Node* stack = NULL;
    Node* queue = NULL;
    Node* list = NULL;
    bool isDigit = false;
    readString(&stack, &queue, &isDigit);
    buildList(&list, &queue, &stack, isDigit);
    printf("\n\n\nLISTA FINAL: \n");
    printList(list);

    return 0;
}

