//เรียกใข้ .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //เก็บข้อมูล
    struct Node *link;  //เก็บสถานที่ของโหนดถัดไป
};

void addHead(struct Node** head);
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
    addHead(&head);
    printf("\nAfter ");
    display(head);
}

void addHead(struct Node** head){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));   //สร้างโหนดใหม่และจองพท. ใน memory

    //รับค่าและเก็บไว้ในโหนดใหม่
    int num;
    printf("Input value to add head: ");
    scanf("%d",&num);
    newnode->data = num;

    newnode->link = *head;  //ให้โหนดใหม่ชี้ไปที่ head
    *head = newnode;        //และให้พอยเตอร์ head เท่ากับโหนดใหม่

}

void display(struct Node* head){
    struct Node *p = head;  //สร้างพอยเตอร์ p เท่ากับพอยเตอร์ head

    //แสดงค่าใน linkedlist
    while(p != NULL){
        printf("[%d] ",p->data);
        p = p->link;
    }
}
