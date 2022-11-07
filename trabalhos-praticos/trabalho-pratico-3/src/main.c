#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isAvlTree = true;

typedef struct node {
    int data;
    int height;
    struct node* pLeft;
    struct node* pRight;
} node;

/*
===================================
freeNode

    free node
===================================
*/
void freeNode(node* node) {
    if (node == NULL) return;

    freeNode(node->pLeft);
    freeNode(node->pRight);
    free(node);

    node = NULL;
}

/*
===================================
freeTree

    free tree
===================================
*/
void freeTree(node** root) {
    if (root == NULL) return;

    freeNode(*root);

    free(root);    
}

/*
================================================
greater

    return the greater value between two numbers
================================================
*/
int greater(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

/*
========================================
nodeHeight

    return height the of the node passed
    if node is NULL, return -1
========================================
*/
int nodeHeight(node* node) {
    if (node == NULL) {
        return -1;
    } else {
        return node->height;
    } 
}

/*
=======================================
balanceFactor

    return the balance factor of a node
=======================================
*/
int balanceFactor(node* node) {
    return labs(nodeHeight(node->pLeft) - nodeHeight(node->pRight));
}

/*
=====================================
createNode
    creates a new node and returns it
=====================================
*/
node* createNode(int data){

    node* nodePtr = malloc(sizeof(node));

    if (nodePtr != NULL) {
        nodePtr->data = data;
        nodePtr->height = 0;
        nodePtr->pLeft = NULL;
        nodePtr->pRight = NULL;
    }
    
    return nodePtr;
}

/*
===================================
insert

    insert a new node into the tree
===================================
*/
int insertNode(node** root, int data) {

    if (*root == NULL) {
        *root = createNode(data);
        return true;
    }

    node *rootPtr = *root;

    if (data < rootPtr->data) {

        if (insertNode(&rootPtr->pLeft, data)) {

            if (balanceFactor(rootPtr) >= 2) {
                isAvlTree = false;
            }
        }
    } else {
        if (data > rootPtr->data) {

            if (insertNode(&rootPtr->pRight, data)) {

                if (balanceFactor(rootPtr) >= 2) {
                    isAvlTree = false;
                }
            }
        } else {
            printf("Duplicated value!");
            return 0;
        }
    }

    rootPtr->height = greater(nodeHeight(rootPtr->pLeft), nodeHeight(rootPtr->pRight)) + 1;

    return 1;
}

/*
=======================
inOrder

    print tree in order
=======================
*/
void inOrder(node* root) {
    if (root == NULL) return;

    inOrder(root->pLeft);
    printf("%d, ", root->data);
    inOrder(root->pRight);
}

int main(int argc, char const *argv[]) {

    //------------------------------------------------
    //Create tree root
    struct node* root = malloc(sizeof(node));

    if (root == NULL) {
        printf("Error!");
        exit(1);
    }

    root = NULL;
    //------------------------------------------------
    
    int option, value;

    do {
        printf("\nInserir valor (1)");
        printf("\nSair e verificar arvore (0)\n");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &value);

            if (!insertNode(&root, value)) {
                printf("\nFalha na inserçao do dado!");
            }
            break;

        case 0:
            printf(isAvlTree ? "É uma arvore AVL!\n" : "Não é uma arvore AVL!\n");
            printf("Saindo.");



            exit(1);
            break;

        default:
            printf("Opçao invalida!\n");
            break;
        }
    } while (option != 1 || option != 0);

    return 0;
}