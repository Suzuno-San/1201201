//เรียกใช้ .h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;           //เก็บข้อมูล
    struct Node *link;  //เก็บสถานที่ของnodeถัดไป
};

//ประกาศ function
int countelementlist(struct Node* head);
bool searchlistlist(struct Node* head, int key);
void displaylinklist(struct Node* head);

void main(){
    //ประกาศตัวแปรเพื่อสร้าง node
    struct Node *head;      //ประกาศตัวแปร head เป็น  pointer เพื่อเก็บสถานที่ของnodeแรก
    struct Node *first;     //ประกาศตัวแปร first
    struct Node *second;    //ประกาศตัวแปร second
    struct Node *third;     //ประกาศตัวแปร third

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

    //เรียกใช้ function displaylinklist เพื่อแสดงค่าข้อมูลใน list
    displaylinklist(head);

    //เรียกใช้ function countelementlist เก็บไว้ในตัวแปร count เก็บจำนวนข้อมูลใน list และแสดงค่าออกมา
    int count = countelementlist(head);
    printf("Count of LinkList is %d\n",count);

    //รับค่า key
    int key;
    printf("\nInput Key for Search: ");
    scanf("%d",&key);

    //เรียกใช้ function searchlistlist เก็บค่าที่ return ไว้ในตัวแปร found
    bool found = searchlistlist(head,key);
    if(found == true){                              //ถ้า found มีค่าเท่ากับ true ให้พิมพ์ Found
        printf("%d Found in LinkedList\n",key);
    }
    else{                                           //ถ้า  found มีค่าเท่ากับ false ให้พิมพ์ Not Found
        printf("%d Not Found in LinkedList\n",key);
    }
}

//ฟังก์ชันนับจำนวน elementlist
int countelementlist(struct Node* head){
    //ประกาศตัวแปรพอยต์เตอร์ p เพื่อเลื่อนไปในการแสดงค่าข้อมูล ใน list
    struct Node* p = NULL;

    p = head;           //ให้ p เท่ากับ head
    int count;          //ประกาศตัวแปร count เป็นจำนวนเต็ม
    printf("\n");
    while(p != NULL){   //เงื่อนไขการทำซ้ำ ด้วยเงื่อนไข p ไม่เท่ากับค่าว่าง
        count++;        //ให้ count เพิ่มขึ้น 1
        p = p->link;    //ให้พอยต์เตอร์ p ชี้ไปยัง node ต่อไป
    }

    return count;      //คืนค่า count
}

//ฟังก์ชันค้นหา elementlist
bool searchlistlist(struct Node* head,int key){
    //ประกาศตัวแปรพอยต์เตอร์ p เพื่อเลื่อนไปในการแสดงค่าข้อมูล ใน list
    struct Node* p = NULL;

    p = head;                   //ให้ p เท่ากับ head
    bool found = false;         //ประกาศตัวแปร found เป็น boolean มีค่าเป็นเท็จ
    while((p != NULL)&&(found != true)){    //เงื่อนไขการทำซ้ำ ด้วยเงื่อนไข p ไม่เท่ากับค่าว่าง และ found ไม่เป็นจริง
        if(p->data == key){     //เงื่อนไขว่า ข้อมูลใน node p มีค่าเท่า key
            found = true;       //ให้ found เป็นจริง
        }
        p = p->link;            //ให้พอยต์เตอร์ p ชี้ไปยัง node ต่อไป
    }
    return found;       //คืนค่า found
}

void displaylinklist(struct Node* head){
    //ประกาศ pointer p เพื่อเลื่อนไปในการแสดงค่าข้อมูล ใน list
    struct Node* p = NULL;

    p = head;                           //กำหนดให้ pointer p ชี้ไป node แรก
    printf("\n");
    while(p != NULL){                   //เงื่อนไขการทำซ้ำ ด้วยเงื่อนไข p ไม่เท่ากับค่าว่าง
        if(p->link != NULL){            //เงื่อนไขว่า link ใน node p ไม่ตรงกับค่าว่าง
            printf("[%d]->",p->data);
        }
        else{
            printf("[%d]",p->data);
        }
        p = p->link;        //ให้พอยต์เตอร์ p ชี้ไปยัง node ต่อไป
    }
    printf("\n");
}
