#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* pushS(Node *stack, int num) {
    Node *newNode = malloc(sizeof(Node));
    
    if(newNode) {
        newNode->data = num;
        newNode->next = stack;
        return newNode;
    } else {
        printf("\n Error allocating memory. \n");
    }
    return NULL;
}

Node* pop(Node **stack) {
    if(*stack != NULL) {
        Node *remove = *stack;
        *stack = remove->next;
        return remove;
    } else {
        printf("\n Empty stack. \n");
    }
    return NULL;
}

void printS(Node *list) {
    printf("\n Stack: ");
    while (list) {
        printf("%d ", list->data);
        list = list->next;
    }
    
}

int main() {
    Node *stack = NULL;

    stack = pushS(stack, 0);
    stack = pushS(stack, 10);
    stack = pushS(stack, 20);
    pop(&stack);
    printS(stack);
}