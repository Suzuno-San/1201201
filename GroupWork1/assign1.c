#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

void push(struct Node** head, int data);
void display(struct Node* head);

void main(){
    struct Node* head = NULL;

    int num,base,quotient;
    float fraction;

    printf("Input number: ");
    scanf("%d",&num);
    printf("Input base number: ");
    scanf("%d",&base);
    quotient = num;

    while(quotient != 0){
        push(&head,quotient%base);
        quotient = quotient/base;
    }
    printf("result is (%d)%d = (",num,10);
    display(head);
    printf(")%d\n\n",base);

}

void push(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    newNode->link = *head;
    *head = newNode;
}

void display(struct Node* head){
    struct Node* p = head;

    while(p != NULL){
        printf("%d",p->data);
        p = p->link;
    }
}
