#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 5

int stack_arr[MAX];
int top = -1; //"-1" indicates that the stack is empty
int data;

void PUSH(int data) {

    if (top != -1 && top == MAX-1) {
        printf("Stack is full!\n");
        return;
    }
    
    top++;

    stack_arr[top] = data;
}

int POP() {

    if (top < 0) {
        printf("Stack is empty!\n");
        exit(1);
    } else {
        data = stack_arr[top];
        top--;
        return data;
    }
}

void printStack() {
    for (int i = 0; i < MAX; i++) {
        printf("%d | ", stack_arr[i]);
    } 
}

int main() {

    PUSH(1);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    PUSH(5);
    data = POP();
    printf("POP Data: %d\n", data);
    data = POP();
    printf("POP Data: %d\n", data);
    data = POP();
    printf("POP Data: %d\n", data);
    data = POP();
    printf("POP Data: %d\n", data);
    data = POP();
    printf("POP Data: %d\n", data);
    PUSH(10);
    PUSH(10);
    PUSH(10);
    PUSH(10);
    PUSH(10);
    POP();
    PUSH(12);

    printStack(stack_arr);
    return 0;
}