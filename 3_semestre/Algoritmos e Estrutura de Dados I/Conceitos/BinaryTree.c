#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(Node *root) {
    if(root != NULL) {
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    else
        return;
}
void inorder(Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
    else
        return;
}
void postorder(Node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
    else
        return;
}

int search(Node *root, int num) {
    if(root == NULL) {
        printf("Empty tree!\n");
        return -99999;
    }
    if(num == root->data)
        return root->data;
    if(num < root->data)
        return search(root->left, num);
    if(num > root->data)
        return search(root->right, num);
}

Node* insert(Node *root, int num) {
    if(root == NULL)
        return createNode(num);
    if(num < root->data)
        root->left = insert(root->left, num);
    else if(num > root->data)
        root->right = insert(root->right, num);
    return root;
}

int main() {
    Node *root = createNode(5);

    insert(root, 25);
    insert(root, 22);
    insert(root, 40);
    insert(root, 30);
    insert(root, 45);
    insert(root, 27);
    insert(root, 20);
    insert(root, 48);

    printf("PRE-ORDER: \n");
    preorder(root);

    printf("IN-ORDER: \n");
    inorder(root);

    printf("POST-ORDER: \n");
    postorder(root);

    printf("FIND NUMBER: \n");
    printf("%d\n", search(root, 32));
}