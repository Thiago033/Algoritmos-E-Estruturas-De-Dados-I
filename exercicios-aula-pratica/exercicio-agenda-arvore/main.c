#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char *name;
    int age;
    char *phone;

    char *key;

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
===================================
isEmpty

    checks if the tree is empty
    return 1 if the tree is empty
    return 0 if not
===================================
*/
int isEmpty(node** root) {
    if (root == NULL) return 1;
    
    if (*root == NULL) return 1;

    return 0;
}

/*
===================================
treeHeight

    tree height
===================================
*/
int treeHeight(node** root) {

    node* rootPtr = *root;

    if (root == NULL) return 0;

    if (rootPtr == NULL) return 0;

    int leftHeight = treeHeight(&rootPtr->pLeft);
    int rightHeight = treeHeight(&rootPtr->pRight);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

/*
===================================
totalNodes

    total nodes
===================================
*/
int totalNodes(node** root) {
    node* rootPtr = *root;

    if (root == NULL) return 0;

    if (rootPtr == NULL) return 0;

    int totalLeft = totalNodes(&rootPtr->pLeft);
    int totalRight = totalNodes(&rootPtr->pRight);

    return (totalLeft + totalRight + 1);
}

/*
===================================
preOrder

    pre order
===================================
*/
void preOrder(node* root) {
    if (root == NULL) return;

    printf("=================\n");
    printf("name: %s\n", root->name);
    printf("age: %d\n", root->age);
    printf("phone: %s\n", root->phone);
    preOrder(root->pLeft);
    preOrder(root->pRight);
}

/*
===================================
inOrder

    in order
===================================
*/
void inOrder(node* root) {
    if (root == NULL) return;

    inOrder(root->pLeft);
    printf("=================\n");
    printf("name: %s\n", root->name);
    printf("age: %d\n", root->age);
    printf("phone: %s\n", root->phone);
    inOrder(root->pRight);
}

/*
===================================
postOrder

    post order
===================================
*/
void postOrder(node* root) {
    if (root == NULL) return;

    postOrder(root->pLeft);
    postOrder(root->pRight);
    printf("=================\n");
    printf("name: %s\n", root->name);
    printf("age: %d\n", root->age);
    printf("phone: %s\n", root->phone);
}


/*
=========================================
minValueNode

    find minimum value node and return it
=========================================
*/
struct node* minValueNode(struct node* node) {
    struct node* current = node;
  
    //loop down to find the leftmost leaf
    while (current && current->pLeft != NULL) {
        current = current->pLeft;
    }
        
    return current;
}

// /*
// =========================================
// removeNode

//     remove a node
// =========================================
// */
// node* removeNode(node* root, int key) {

//     if (root == NULL) {
//         return root;
//     }
  
//     if (key < root->data) {
//         root->pLeft = removeNode(root->pLeft, key);
  
//     } else if (key > root->data) {
//         root->pRight = removeNode(root->pRight, key);
  
//     } else {
//         if (root->pLeft == NULL) {
//             struct node* temp = root->pRight;
//             free(root);
//             return temp;
//         }
//         else if (root->pRight == NULL) {
//             struct node* temp = root->pLeft;
//             free(root);
//             return temp;
//         }
  
//         struct node* temp = minValueNode(root->pRight);

//         root->data = temp->data;
  
//         root->pRight = removeNode(root->pRight, temp->data);
//     }

//     return root;
// }

// /*
// ===================================
// find

//     find a node in the tree
// ===================================
// */
// bool find(node *root, int key) {
//     if (root == NULL) return false;

//     if (root->data == key) return true;

//     //greater than the root value
//     if (key > root->data) {
//         return find(root->pRight, key);
//     }

//     //less than the root value
//     if (key < root->data) {
//         return find(root->pLeft, key);
//     }
// }

/*
===================================
    create a new node
===================================
*/
node* createNode(char name[], int age, char phone[], int key) {

    node *newNode = malloc(sizeof(node));

    newNode->name = (char *) (malloc(sizeof(name)));
    newNode->phone = (char *) (malloc(sizeof(phone)));

    if (newNode != NULL) {
        strcpy(newNode->name, name);
        newNode->age = age;
        strcpy(newNode->phone, phone);

        newNode->pLeft = NULL;
        newNode->pRight = NULL;


        //defining the key
        if (key == 1) {
            newNode->key = (char *) malloc(sizeof(name));

            strcpy(newNode->key, name);

        } else if (key == 2) {
            newNode->key = malloc(sizeof(age));

            sprintf(newNode->key, "%d", age);

        } else {
            newNode->key = (char *) malloc(sizeof(phone));

            strcpy(newNode->key, phone);

        }
    }

    return newNode;
}

/*
===================================
insert

    insert a new node into the tree
===================================
*/
bool insert(node** root, node* newNode) {

    node *rootPtr = *root;

    if (rootPtr == NULL) {
        *root = newNode;
        return true;
    }
    

    //less or equal than the root value
    if (strcmp(newNode->key, rootPtr->key) <= 0) {
        return insert(&(rootPtr->pLeft), newNode);
    } 

    //greater than the root value
    if (strcmp(newNode->key, rootPtr->key) > 0) {
        return insert(&(rootPtr->pRight), newNode);
    }
}

int main(int argc, char const *argv[]) {
    
    //create root
    node *root = malloc(sizeof(node));

    if (root == NULL) {
        printf("Error!");
        exit(1);
    }

    root = NULL;
    //---------------------------------------------------

    int option, key;

	int age;
    char name[30], phone[20];
	
    printf ("==========================\n");
    printf ("1 - name \n");
    printf ("2 - age \n");
    printf ("3 - phone \n");
    printf ("==========================\n");
    printf ("Key: ");
    scanf ("%d", &key);

    do {
        printf ("==========================\n");
        printf("1) Insert       \n");
        printf("2) Delete   \n");
        printf("3) Print       \n");
        printf("4) Search       \n");
        printf("5) Quit         \n");
        printf ("==========================\n");
        scanf("%d", &option);
        
        switch (option) {

        case 1:
            //INSERT

            printf("Insert data:    \n");
            printf("Name:           \n");
            scanf("%s", name           );
            printf("Age:            \n");
            scanf("%d", &age           );
            printf("Phone number:   \n");
            scanf("%s", phone          );

        
            insert(&root, createNode(name, age, phone, key));
    
            break;
        
        case 2:
            //DELETE
			
            break;

        case 3:
            //PRINT

            do {
                printf ("==========================\n");
				printf ("Print tipe:    \n");
				printf ("1 - Post Order  \n");
				printf ("2 - In Order   \n");
				printf ("3 - Pre Order \n");
				scanf ("%d", &option);
                printf ("==========================\n");

                switch(option) {

                case 1:
                    printf("Post Order: \n");
                    postOrder(root);
                    break;

                case 2:
                    printf("In Order: \n");
                    inOrder(root);
                    break;

                case 3:
                    printf("Pre Order: \n");
                    preOrder(root);
                    break;
                
                default:
                    printf("Invalid option! try again!\n");
                    break;
                }
			} while (option < 1 || option > 3);

            break;
        
        case 4:
            //SEARCH

            break;
        
        case 5:
            //QUIT

            printf("Quit.\n");
            return 0;
            break;
        
        default:
            printf("Invalid option! try again!\n");
            break;
        }

    } while (option != 0);


    // removeNode(root, 2);

    // printf("\n\nTREE HEIGHT\n");
    // printf("%d\n", treeHeight(&root));

    // printf("TOTAL NODES\n");
    // printf("%d\n", totalNodes(&root));

    // printf("MINIMUM NODE\n");
    // node* minimumNode = minValueNode(root);
    // printf("%d\n\n", minimumNode->data);

    // if (isEmpty(&root)) {
    //     printf("Tree is empty!\n\n");
    // } else {
    //     printf("Tree isn't empty!\n\n");
    // }

    // printf("FINDING ON TREE: (0) FALSE | (1) TRUE\n");
    // printf("%d (%d)\n", 16, find(root, 16));
    // printf("%d (%d)\n", 50, find(root, 50));
    // printf("%d (%d)\n", 5, find(root, 5));

    return 0;
}