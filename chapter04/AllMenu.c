//เรียกใช้ .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //เก็บข้อมูล
    struct Node *link;  //เก็บสถานที่ของโหนดถัดไป
};

//ประกาศ function
void menu(struct Node* head);
void addHead(struct Node** head);
void addTail(struct Node** head);
void addWithOrder(struct Node** head);
void deleteHead(struct Node** head);
void deleteTail(struct Node** head);
void deleteRequireNode(struct Node** head);
void displayLinklist(struct Node* head);

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

    menu(head);     //เรียกฟังก์ชัน Menu
}

void menu(struct Node* head){
    int choice = 1;     //ประกาศตัวแปร choice เพื่อเก็บตัวเลือก

    //เงื่อนไขทำซ้ำคือ ถ้า choice ไม่เท่ากับ 0
    while(choice != 0){
        printf("******Program Linked List******\n");
        printf("1. Add head\n");
        printf("2. Add tail\n");
        printf("3. Add with order\n");
        printf("4. Delete head\n");
        printf("5. Delete tail\n");
        printf("6. Delete requireNode\n");
        printf("7. Display\n\n");

        printf("Type number [<= to select the option =>]: ");
        scanf("%d", &choice);

        //ถ้า choice เท่ากับ 0 พิมพ์ข้อความ "Good Bye."
        if(choice == 0){
            printf("\nGood Bye.\n");
        }

        //ถ้า choice เท่ากับ 1 ให้เรียกฟังก์ชันเพิ่มข้างหน้า
        else if(choice == 1){
            printf("\n");
            addHead(&head);
            printf("\n");
        }

        //ถ้า choice เท่ากับ 2 ให้เรียกฟังก์ชันเพิ่มข้างหลัง
        else if(choice == 2){
            printf("\n");
            addTail(&head);
            printf("\n");
        }

        //ถ้า choice เท่ากับ 3 ให้เรียกฟังก์ชันเพิ่มแบบลำดับ
        else if(choice == 3){
            printf("\n");
            addWithOrder(&head);
            printf("\n");
        }

        //ถ้า choice เท่ากับ 2 ให้เรียกฟังก์ชันลบส่วนหัว
        else if(choice == 4){
            printf("\n");
            deleteHead(&head);
            printf("\n");
        }

        //ถ้า choice เท่ากับ 3 ให้เรียกฟังก์ชันลบส่วนท้าย
        else if(choice == 5){
            printf("\n");
            deleteTail(&head);
            printf("\n");
        }

        //ถ้า choice เท่ากับ 4 ให้เรียกฟังก์ชันลบตัวที่ต้องการ
        else if(choice == 6){
            printf("\n");
            deleteRequireNode(&head);
            printf("\n");
        }

        //ถ้า choice เท่ากับ 5 ให้เรียกฟังก์ชันแสดงข้อมูลใน linkedlist
        else if(choice == 7){
            printf("\n");
            displayLinklist(head);
            printf("\n");
        }

        //ถ้า choice ไม่ตรงกับเงื่อนไขใดเลย ให้พิมพ์ข้อความ "Please try again."
        else{
            printf("\nPlease try again.\n\n");
        }
    }
}

void addHead(struct Node** head){
    struct Node* l = (struct Node*)malloc(sizeof(struct Node));     //ประการโหนดใหม่

    //รับค่าข้อมูลแล้วเก็บในโหนดใหม่
    int num;
    printf("Input value to add: ");
    scanf("%d",&num);
    l->data = num;

    l->link = *head;     //ให้โหนดใหม่ชี้ไปยังโหนดที่ head ชี้ไป
    *head = l;           //ให้ head ชี้ไปยังโหนด l

    printf("Add [%d] Completed.\n",num);
}

void addTail(struct Node** head){
    struct Node* l = (struct Node*)malloc(sizeof(struct Node));     //ประการโหนดใหม่
    struct Node* p = *head;
    struct Node* last;

    //รับค่าข้อมูลแล้วเก็บในโหนดใหม่
    int num;
    printf("Input value to add: ");
    scanf("%d",&num);
    l->data = num;

    //ให้พอยเตอร์ l ชี้ไป Null
    l->link = NULL;

    //ตรวจสอบลิงค์สิสต์ว่างหรือไม่
    if(*head == NULL){
        l->link = *head;     //ให้ l ชี้ไป head
        *head = l;           //ให้พอยเตอร์ head เท่ากับ พอยต์เตอร์ l
    }
    else{
        //เงื่อนไขว่าพอยต์เตอร์ p ที่ชี้ไปเท่ากับค่าว่างหรือไม่
        while(p->link != NULL){
            p = p->link;    //ให้พอยต์เตอร์ p ไปยังโหนดต่อไป
            last = p;       //ให้พอยต์เตอร์ last เท่ากับพอยเตอร์ p
        }
        last->link = l;        //ให้พอยต์เตอร์ last ชี้ไปพอยต์เตอร์ l
    }
    printf("Add [%d] Completed.\n",num);
}

//ฟังก์ชั่น addWithOrder มีพารามิเตอร์เป็นพอยต์เตอร์ head
void addWithOrder(struct Node** head){
    struct Node* l = (struct Node*)malloc(sizeof(struct Node)); //ประกาศพอยต์เตอร์ l ให้ชี้ไปยังโหนดใหม่
    struct Node* tmp;   //ประกาศพอยต์เตอร์  tmp

    //รับค่าเป็นจำนวนเต็มเก็บไว้ในตัวแปร num
    int num;
    printf("Input value to add: ");
    scanf("%d",&num);

    l->data = num;      //กำหนดค่าให้พอยต์เตอร์  l เท่ากับ num

    //ตรวจสอบลิงค์สิสต์ว่าง หรือ โหนดใหม่มีค่าน้อยที่สุดหรือไม่
    if(*head == NULL || l->data <= (*head)->data){
        l->link = *head;     //ให้พอยต์เตอร์  l ชี้ไปที่ head
        *head = l;           //ให้พอยต์เตอร์  head เท่ากับพอยต์เตอร์  l
    }
    else{
        tmp = *head;         //ให้พอยต์เตอร์  tmp เท่ากับพอยต์เตอร์ head

        //เงื่อนไขทำซ้ำเพื่อค้นหาโหนดที่มากกว่าโหนดใหม่
        while(tmp->link != NULL && tmp->link->data <= l->data){
            tmp = tmp->link;    //ให้พอยต์เตอร์  tmp ชี้ไปโหนดต่อไป
        }
        l->link = tmp->link;    //ให้โหนดใหม่ชี้ไปที่เดียวกับที่โหนด tmp ชี้ไป
        tmp->link = l;          //ให้โหนดที่ tmp ที่ชี้ไปชี้ไปยังโหนด l
    }
    printf("Add [%d] Completed.\n",num);
}

//ฟังก์ชั่น deleteHead มีพารามิเตอร์เป็นพอยต์เตอร์ head
void deleteHead(struct Node** head){
    //ตรวจสอบลิงค์สิสต์ว่างหรือไม่
    if(*head == NULL){
        printf("This linked list is empty.\n");
    }
    else{
        printf("Delete [%d] Completed.\n",(*head)->data);
        *head = (*head)->link;      //ให้พอยต์เตอร์ head เท่ากับพอยต์เตอร์ head ตัวถัดไป
    }
}

void deleteTail(struct Node** head){
    struct Node* tmp = *head;    //ประกาศพอยต์เตอร์  tmp เท่ากับพอยต์เตอร์ head

    //ตรวจสอบลิงค์สิสต์ว่างหรือไม่
    if(*head == NULL){
        printf("This linked list is empty.\n");
    }
    else if(tmp->link == NULL){ //ถ้าเหลือโหนด อยู่ตัวเดียว
        printf("Delete [%d] Completed.\n",tmp->data);
        *head = NULL;    //ให้พอยต์เตอร์ head เท่ากับค่าว่าง
    }
    else{
        //เงื่อนไขทำซ้ำว่า พอยต์เตอร์ tmp ตัวถัดๆไป ไม่เท่ากับ ค่าว่าง
        while(tmp->link->link != NULL){
            tmp = tmp->link;        //เลื่อนพอยต์เตอร์ไปยังโหนดถัดไป
        }
        printf("Delete [%d] Completed.\n",tmp->link->data);
        tmp->link = NULL;   //ให้พอยต์เตอร์ tmp ตัวถัดไปเท่ากับค่าว่าง
    }
}

void deleteRequireNode(struct Node** head){
    struct Node* p;         //ประกาศพอยต์เตอร์  p
    struct Node* tmp;       //ประกาศพอยต์เตอร์  tmp
    int num;                //ประกาศตัวแปร num เป็นจำนวนเต็ม

    //ตรวจสอบลิงค์สิสต์ว่างหรือไม่
    if(*head == NULL){
        printf("This linked list is empty.\n");
    }
    else{
        //รับค่าเก็บไว้ในตัวแปร num
        printf("Input value to delete: ");
        scanf("%d",&num);

        tmp = *head;     //ให้พอยต์เตอร์ tmp เท่ากับพอยต์เตอร์ head

        //ทำซ้ำเพื่อค้นหาค่าข้อมูลแต่ละโหนดที่มีค่าเท่ากับ num
        while(tmp->data != num && tmp->link != NULL){
            p = tmp;            //ให้พอยต์เตอร์ P เป็นพอยต์เตอร์ชั่วคราวชี้ตาม tmp
            tmp = tmp->link;    //เลื่อน tmp ไปยังโหนดถัดไป
        }
        //เงื่อนไขถ้าค้นหา num ไม่เจอ
        if(tmp->data != num){
            printf("Node not found.\n");
        }
        else{
            //ตรวจสอบโหนดที่ต้องการลบเป็นโหนดแรกหรือไม่
            if(tmp == *head){
            printf("Delete [%d] Completed.\n",tmp->data);
            *head = tmp->link;   //ให้พอยต์เตอร์ head เท่ากับพอยต์เตอร์ tmp ตัวถัดไป
        }
            else{
                printf("Delete [%d] Completed.\n",tmp->data);
                p->link = tmp->link;    //ให้พอยต์เตอร์ p ชี้ไปยังพอยต์เตอร์ tmp ตัวถัดไป
            }
        }
    }
}

void displayLinklist(struct Node* head){
    //ประกาศพอยต์เตอร์ p เพื่อเลื่อนไปในการแสดงค่าข้อมูล ใน list
    struct Node* p = NULL;

    p = head; //กำหนดให้พอยเตอร์ p ชี้ไปโหนดแรก

    //เงื่อนไขว่าถ้าลิงค์ลิสต์ว่าง
    if(p == NULL){
        printf("[]");
    }
    //ตรวจสอบลิงค์สิสต์ว่างหรือไม่
    while(p != NULL){
        //
        if(p->link != NULL){        //เงื่อนไขว่าพอยต์เตอร์ p ตัวถัดไปไม่ใช่ค่าว่าง
            printf("[%d]->",p->data);
        }
        else{
            printf("[%d]",p->data);
        }
        p = p->link;    //ให้พอยต์เตอร์ p ชี้ไปยัง node ต่อไป
    }
    printf("\n");
}

