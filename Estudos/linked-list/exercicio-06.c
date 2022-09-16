#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int nodesCounter(struct node *head) {
    int count = 0;

    if (head == NULL) printf("Linked list is empty!");

    struct node *ptr = NULL;
    ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    return count;
}

void printList(struct node *head) {
    if (head == NULL) printf("Linked list is empty!");

    struct node *ptr = NULL;
    ptr = head;

    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// //1st version
// void addAtEnd(struct node *head, int data){
//     struct node *ptr, *temp;

//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->next = NULL;

//     ptr = head;

//     while (ptr->next != NULL){
//         ptr = ptr->next;
//     }

//     ptr->next = temp;
// }

//2nd version
struct node* addAtEnd(struct node *ptr, int data){
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    ptr->next = temp;
    return temp;
}

//1st version
// struct node* addAtBeginning(struct node *head, int data) {
//     struct node *temp;

//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->next = head;
//     head = temp;
//     return head;
// }

//2nd version
void addAtBeginning(struct node **head, int data) {
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    temp->next = *head;
    *head = temp;
}

void addAtCertainPosition(struct node *head, int data, int pos) {

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    struct node *ptr = head;
    pos--;

    while (pos != 1) {
        ptr = ptr->next;
        pos--;
    }

    temp->next = ptr->next;
    ptr->next = temp;

}

struct node* del_first(struct node *head){
    if (head == NULL) printf("Linked list is empty!");
    else {
        struct node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    
    return head;
}

//1st version
// struct node* del_last(struct node *head) {
//     if (head == NULL) printf("Linked list is empty!");
//     else if (head->next == NULL){
//         free(head)
//         head = NULL;
//     } else {
//         struct node *temp = head;
//         struct node *temp2 = head;

//         while (temp->next != NULL) {
//             temp2 = temp;
//             temp = temp->next;
//         }

//         temp2->next = NULL;
//         free(temp);
//         temp = NULL;
//     }

//     return head;
// }

//2nd version
struct node* del_last(struct node *head) {
    if (head == NULL) printf("Linked list is empty!");
    else if (head->next == NULL){
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }

    return head;
}

struct node* del_pos(struct node **head, int position) {

    struct node *current = *head;
    struct node *previous = *head;

    if (*head == NULL) printf("Linked list is empty!");
    else if (position == 1){
        *head = current->next;
        free(current);
        current = NULL;
    } else {
        while (position != 1)
        {
            previous = current;
            current = current->next;
            position--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

struct node* del_list(struct node *head){
    struct node *temp = head;

    while (temp != NULL) {
        temp = temp->next;
        free(head);
        head = temp;
    }
    
}

int main(int argc, char const *argv[]) {
    struct node *head = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = NULL;

    struct node *ptr = head;
    // struct node *current = (struct node *)malloc(sizeof(struct node));
    // current->data = 2;
    // current->next = NULL;
    // head->next = current;

    // current = (struct node *)malloc(sizeof(struct node));
    // current->data = 3;
    // current->next = NULL;
    // head->next->next = current;

    ptr = addAtEnd(ptr, 2);
    ptr = addAtEnd(ptr, 3);
    ptr = addAtEnd(ptr, 4);

    //head = addAtBeginning(head, 5);
    addAtBeginning(&head, 5);

    addAtCertainPosition(head, 10, 4);
    addAtCertainPosition(head, 11, 5);
    addAtCertainPosition(head, 12, 2);

    addAtBeginning(&head, 89);

    head = del_first(head);

    del_pos(&head, 5);

    del_last(head);

    

    printf("Nodes counter: %d\n", nodesCounter(head));
    printList(head);
    printf("head: %d\n", head->data);


    printf("AFTER DEL_LIST\n");
    head = del_list(head);
    printf("Nodes counter: %d\n", nodesCounter(head));
    printList(head);
    printf("head: %d\n", head->data);
    return 0;
}