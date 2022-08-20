//เรียกใข้ .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //เก็บข้อมูล
    struct Node *link;  //เก็บสถานที่ของโหนดถัดไป
};

void deleteRequireNode(struct Node** head);
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
    deleteRequireNode(&head);
    printf("\nAfter ");
    display(head);
}

void deleteRequireNode(struct Node** head){
    struct Node* p;             //ประกาศพอยเตอร์ p
    struct Node* tmp = *head;   //ประกาศพอยเตอร์ tmp เท่ากับ head

    //รับค่า ไว้ไนตัวแปร num
    int num;
    printf("Input value to delete: ");
    scanf("%d",&num);

    //ถ้า linkedlist เป็นค่าว่าง
    if(*head == NULL){
        printf("Linkedlist is empty.");
    }
    else{
        //เงื่อนไขทำซ้ำ ว่า tmp ไม่เท่ากับ num และ โหนดถัดไปไม่เป็นค่าว่าง
        while(tmp->data != num && tmp->link != NULL){
            p = tmp;            //พอยเตอร์ p เท่ากับพอยเตอร์ tmp
            tmp = tmp->link;    //เลื่อนไปโหนดถัดไป
        }
        //พอยเตอร์ tmp มีค่าไม่เท่ากับ num
        if(tmp->data != num){
            printf("Node not found.\n");
        }
        else{
            //ถ้า tmp เท่ากับ head
            if(tmp == *head){
                *head = tmp->link;  //ให้ head เท่ากับ โหนดถัดไป
            }
            else{
                p->link = tmp->link;    //พอยเตอร์ p ชี้ไปโหนดถัดไปของพอยเตอร์ tmp
            }
        }
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



