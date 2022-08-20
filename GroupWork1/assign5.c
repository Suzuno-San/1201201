#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node{
    int data;
    struct Node *link;
};

int calculate(char x, int num1, int num2);
void push(struct Node** head, int data);
int pop(struct Node** head);

void main(){
    struct Node* head;

    head = NULL;

    char x;
    int num1,num2,val;
    printf("Enter Postfix Expression(Ex. 265*+): ");
    while((x=getchar())!='\n'){
        if(isdigit(x)){
            push(&head,x-48);
        }
        else{
            num2 = pop(&head);
            num1 = pop(&head);
            val = calculate(x,num1,num2);
            push(&head,val);
        }
    }

    val = pop(&head);
    printf("Value of expression is %d\n",val);
}

int calculate(char x, int num1, int num2){
    if(x == '+'){
        return num1+num2;
    }
    if(x == '-'){
        return num1-num2;
    }
    if(x == '*'){
        return num1*num2;
    }
    if(x == '/'){
        return num1/num2;
    }
}

void push(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    newNode->link = *head;
    *head = newNode;
}

int pop(struct Node** head){
    int num;
        num = (*head)->data;
        *head = (*head)->link;

    return num;
}


