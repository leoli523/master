#include <stdio.h>
/* 
Linked list implementation of Stack in C
 I'm learning C so it's not that good!
 
 Feel free to leave tips! 
 
 */
 

typedef struct Node {
    int value;    
    struct Node* next;
} Node;

Node* top;

void push(int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = top;
    top = temp;
    printStack();
}

void pop(){
    Node* temp = top;
    if(top == NULL) return;
    top = temp->next;
    free(temp);
    printStack();
}

int peek(){
    return top->value;
}

char* isEmpty(){
    Node* temp = top;
    int i = 0;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i == 0 ? "Empty" : "Not Empty";
}

void printStack(){
    Node* temp = top;
    while(temp != NULL){
        printf("%d", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(void){
    printf("%s\n", isEmpty());
    push(3);
    push(4);
    push(5);
    pop();
    printf("%s\n", isEmpty());
    pop();
    pop();
    printf("%s\n", isEmpty());
    return 0;
}
