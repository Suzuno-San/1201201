#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *link;
};

void selectChoise(struct Node* head);
struct Node* addWithOrder(struct Node* head);
struct Node* deleteHead(struct Node* head);
struct Node* deleteTail(struct Node* head);
struct Node* deleteRequireNode(struct Node* head);
void displayLinklist(struct Node* head);

void main(){
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    //จองพท. ในหน่วยความจำ
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //กำหนดค่าให้แก่ node
    first->data = 10;
    first->link = NULL;
    second->data =20;
    second->link = NULL;
    third->data =30;
    third->link = NULL;

    //กำหนดการเชื่อมโยง
    head = first;           //ให้ pointer head ชี้ไปที่ first
    first->link = second;   //กำหนดให้ first ชี้ไปที่ second
    second->link = third;   //กำหนดให้ second ชี้ไปที่ third

    selectChoise(head);
}

void selectChoise(struct Node* head){
    int choise = 1;

    while(choise != 0){
        printf("******Program Linked List******\n");
        printf("1. Add with order\n");
        printf("2. Delete head\n");
        printf("3. Delete tail\n");
        printf("4. Delete requireNode\n");
        printf("5. Display\n\n");

        printf("Type number [<= to select the option =>]: ");
        scanf("%d", &choise);

        if(choise == 1){
            printf("\n");
            head = addWithOrder(head);
            printf("\n");
        }
        else if(choise == 2){
            printf("\n");
            head = deleteHead(head);
            printf("\n");
        }
        else if(choise == 3){
            printf("\n");
            head = deleteTail(head);
            printf("\n");
        }
        else if(choise == 4){
            printf("\n");
            head = deleteRequireNode(head);
            printf("\n");
        }
        else if(choise == 5){
            printf("\n");
            displayLinklist(head);
            printf("\n");
        }
    }
}

struct Node* addWithOrder(struct Node* head){
    struct Node* L = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tmp;

    int num;
    printf("Input Number: ");
    scanf("%d",&num);

    L->data = num;
    L->link = NULL;

    if(head == NULL || L->data <= head->data){
        L->link = head;
        head = L;
    }
    else{
        tmp = head;
        while(tmp->link != NULL && tmp->link->data <= L->data){
            tmp = tmp->link;
        }
        L->link = tmp->link;
        tmp->link = L;
    }
    return head;
}

struct Node* deleteHead(struct Node* head){
    if(head == NULL){
        printf("This linked list is empty.\n");
    }
    else{
        printf("Delete [%d] Completed.\n",head->data);
        head = head->link;
    }

    return head;
}

struct Node* deleteTail(struct Node* head){
    struct Node* tmp = head;
    struct Node* last;
    struct Node* p;
    if(head == NULL){
        printf("This linked list is empty.\n");
    }
    else if(tmp->link == NULL){ //ถ้าเหลือ node อยู่ตัวเดียว
        printf("Delete [%d] Completed.\n",tmp->data);
        head = NULL;
    }
    else{
        while(tmp->link->link != NULL){
            tmp = tmp->link;
        }
        printf("Delete [%d] Completed.\n",tmp->link->data);
        tmp->link = NULL;
    }

    return head;
}

struct Node* deleteRequireNode(struct Node* head){
    struct Node* P;
    struct Node* tmp;
    int num;

    if(head == NULL){
        printf("This linked list is empty.\n");
    }
    else{
        printf("Input Number to Delete: ");
        scanf("%d",&num);
        tmp = head;
        while(tmp->data != num && tmp->link != NULL){
            P = tmp;
            tmp = tmp->link;
        }
        if(tmp->data != num){
            printf("Node not found.\n");
        }
        else{
            if(tmp == head){
            printf("Delete [%d] Completed.\n",tmp->data);
            head = tmp->link;
        }
            else{
                printf("Delete [%d] Completed.\n",tmp->data);
                P->link = tmp->link;
            }
        }
    }

    return head;
}

void displayLinklist(struct Node* head){
    //ประกาศ pointer p เพื่อเลื่อนไปในการแสดงค่าข้อมูล ใน list
    struct Node* p = NULL;

    p = head; //กำหนดให้ pointer p ชี้ไป node แรก

    while(p != NULL){
        if(p->link != NULL){
            printf("[%d]->",p->data);
        }
        else{
            printf("[%d]",p->data);
        }
        p = p->link;
    }
    if(p == NULL){
        printf("[]");
    }
    printf("\n");
}
