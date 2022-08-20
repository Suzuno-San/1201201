//เรียกใข้ .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //เก็บข้อมูล
    struct Node *link;  //เก็บสถานที่ของโหนดถัดไป
};

void addWithOrder(struct Node** head);
void display(struct Node* head);

void main(){
    //ประกาศตัวแปรเพื่อสร้างโหนด
    struct Node *head;      //ประกาศตัวแปร head เป็นพอยตฺ์เตอร์เพื่อเก็บสถานที่ของโหนดแรก
    struct Node *first;     //ประกาศตัวแปร first
    struct Node *second;    //ประกาศตัวแปร second
    struct Node *third;     //ประกาศตัวแปร third

    //จองพท. ในหน่วยความจำ
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //กำหนดค่าให้แก่โหนด
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

    //เรียกฟังก์ชัน
    printf("Before ");
    display(head);
    printf("\n");
    addWithOrder(&head);
    printf("\nAfter ");
    display(head);
}

void addWithOrder(struct Node** head){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));   //สร้างโหนดใหม่และจองพท. ใน memory
    struct Node *p = *head;     //ประกาศพอยเตอร์ p เท่ากับพอยเตอร์ head

    //รับค่าและเก็บไว้ในโหมดใหม่
    int num;
    printf("Input value to add with order: ");
    scanf("%d",&num);

    newnode->data = num;
    newnode->link = NULL;

    //เงื่อนไขว่าถ้า linkedlist เป็นค่าว่าง หรือ โหนดใหม่มีค่าน้อยที่สุด
    if(*head == NULL || (*head)->data >= newnode->data){
        newnode->link = *head;  //ให้โหนดใหม่ชี้ไปที่พอยเตอร์ head
        *head = newnode;        //ให้พอยเตอร์ head เท่ากับโหนดใหม่
    }
    else{
        //เงื่อนไขทำซ้ำว่า โหนดต่อไปไม่ใช่ค่าว่าง และ โหนดถัดไปมีค่า น้อยกว่าหรือเท่ากับ โหนดใหม่
        while(p->link != NULL && p->link->data <= newnode->data){
            p = p->link;    //ไปโหนดถัดไป
        }
        newnode->link = p->link;    //โหนดใหม่ชี้ไปที่ โหนดถัดไปของพอยเตอร์ p
        p->link = newnode;          //พอยเตอร์ p ชี้ไปที่โหนดใหม่
    }
}

void display(struct Node* head){
    struct Node *p = head;  //สร้างพอยเตอร์ p เท่ากับพอยเตอร์ head

    //แสดงค่าใน linkedlist
    while(p != NULL){
        printf("[%d] ",p->data);
        p = p->link;
    }
}


