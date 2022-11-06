#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    int height;
    struct node* pLeft;
    struct node* pRight;
} node;

/*
======================================================
greaterAndMinorValues

    returns the greater and minor of two passed values
======================================================
*/
void greaterAndMinorValues(int x, int y, int* greaterValue, int* minorValue) {
    if (x > y) {
        *greaterValue = x;
        *minorValue = y;
    } else {
        *greaterValue = y;
        *minorValue = x;
    }
}

/*
==================================
treeHeight

    returns the height of the tree
==================================
*/
int treeHeight(node** root) {
    node* rootPtr = *root;
    if (root == NULL) return 0;
    if (rootPtr == NULL) return 0;


    int leftHeight = treeHeight(&rootPtr->pLeft);
    int rightHeight = treeHeight(&rootPtr->pRight);

    if (leftHeight > rightHeight) {
        return (leftHeight + 1);
    } else {
        return (rightHeight + 1);
    }
}


/*
============================================
checkAvlTree

    checks if the passed tree is an AVL tree
    returns true or false    
============================================
*/
bool checkAvlTree(node** root){

    node* rootPtr = *root;

    int leftHeight = treeHeight(&rootPtr->pLeft);
    int rightHeight = treeHeight(&rootPtr->pRight);
    
    int greater, minor;

    greaterAndMinorValues(leftHeight, rightHeight, &greater, &minor);

    if ((greater - minor) >= 2) {
        return false;
    } else {
        return true;
    }
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
        nodePtr->height = 1;
        nodePtr->pLeft = NULL;
        nodePtr->pRight = NULL;
    }
    
    return nodePtr;
}

/*
=========================
insertNode
    insert a node on tree
=========================
*/
bool insertNode(node** root, int data) {

    if (*root == NULL) {
        *root = createNode(data);
        return true;
    }

    node* rootPtr = *root;

    //duplicated data
    if (data == rootPtr->data) {
        printf("\nValor duplicado!");
        return false;
    }

    //insert left
    if (data < rootPtr->data) {
        return insertNode(&(rootPtr)->pLeft, data);
        //verificar insercao
    }

    //insert right
    if (data > rootPtr->data) {
        return insertNode(&(rootPtr)->pRight, data);
        //verificar insercao
    }

    return true;
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

            checkAvlTree(&root) ? printf("Eh uma arvore AVL!\n") : printf("Nao eh uma arvore AVL!\n");

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