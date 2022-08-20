//เรียกใข้ .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //เก็บข้อมูล
    struct Node *link;  //เก็บสถานที่ของโหนดถัดไป
};

void addTail(struct Node** head);
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
    addTail(&head);
    printf("\nAfter ");
    display(head);
}

void addTail(struct Node** head){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));   //สร้างโหนดใหม่และจองพท. ใน memory
    struct Node* p = *head;     //ประกาศพอยเตอร์ p ให้เท่ากับพอยเตอร์ head
    struct Node* last;          //ประกาศพอยเตอร์  last

    //รับค่าและเก็บไว้ในโหนดใหม่
    int num;
    printf("Input value to add tail: ");
    scanf("%d",&num);

    newnode->data = num;
    newnode->link = NULL;

    //ถ้าโหนดใน linkedlist
    if(*head == NULL){
        (*head)->link = newnode;    //ให้พอยเตอร์ head ชี้ไปโหนดใหม่
    }
    else{
        //เงื่อนไขทำซ้ำ ถ้าพอยเตอร์ p ที่ชี้ไปโหนดต่อไปไม่ค่าว่าง
        while(p->link != NULL){
            p = p->link;    //ไปโหนดถัดไป
            last = p;       //ให้พอยเตอร์ last เท่ากับพอยเตอร์ p
        }
        last->link = newnode;   //ให้พอยเตอร์ last ชี้ไปที่โหนดใหม่
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

