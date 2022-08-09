//���¡�� .h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;           //�红�����
    struct Node *link;  //��ʶҹ���ͧ�˹��Ѵ�
};

//��С�� function
void menu(struct Node* head);
struct Node* addWithOrder(struct Node* head);
struct Node* deleteHead(struct Node* head);
struct Node* deleteTail(struct Node* head);
struct Node* deleteRequireNode(struct Node* head);
void displayLinklist(struct Node* head);

void main(){
    //��С�ȵ�����������ҧ�˹�
    struct Node *head;      //��С�ȵ���� head �繾�µ������������ʶҹ���ͧ�˹��á
    struct Node *first;     //��С�ȵ���� first
    struct Node *second;    //��С�ȵ���� second
    struct Node *third;     //��С�ȵ���� third

    //�ͧ��. �˹��¤�����
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //��˹����������˹�
    first->data = 10;
    first->link = NULL;
    second->data =20;
    second->link = NULL;
    third->data =30;
    third->link = NULL;

    //��˹����������§
    head = first;           //��� pointer head ���价�� first
    first->link = second;   //��˹���� first ���价�� second
    second->link = third;   //��˹���� second ���价�� third

    menu(head);     //���¡�ѧ��ѹ Menu
}

void menu(struct Node* head){
    int choice = 1;     //��С�ȵ���� choice �����纵�����͡

    //���͹䢷ӫ�Ӥ�� ��� choice �����ҡѺ 0
    while(choice != 0){
        printf("******Program Linked List******\n");
        printf("1. Add with order\n");
        printf("2. Delete head\n");
        printf("3. Delete tail\n");
        printf("4. Delete requireNode\n");
        printf("5. Display\n\n");

        printf("Type number [<= to select the option =>]: ");
        scanf("%d", &choice);

        //��� choice ��ҡѺ 0 ������ͤ��� "Good Bye."
        if(choice == 0){
            printf("\nGood Bye.\n");
        }
        //��� choice ��ҡѺ 1 ������¡�ѧ��ѹ����Ẻ�ӴѺ
        else if(choice == 1){
            printf("\n");
            head = addWithOrder(head);
            printf("\n");
        }
        //��� choice ��ҡѺ 2 ������¡�ѧ��ѹź��ǹ���
        else if(choice == 2){
            printf("\n");
            head = deleteHead(head);
            printf("\n");
        }
        //��� choice ��ҡѺ 3 ������¡�ѧ��ѹź��ǹ����
        else if(choice == 3){
            printf("\n");
            head = deleteTail(head);
            printf("\n");
        }
        //��� choice ��ҡѺ 4 ������¡�ѧ��ѹź��Ƿ���ͧ���
        else if(choice == 4){
            printf("\n");
            head = deleteRequireNode(head);
            printf("\n");
        }
        //��� choice ��ҡѺ 5 ������¡�ѧ��ѹ�ʴ�������� linkedlist
        else if(choice == 5){
            printf("\n");
            displayLinklist(head);
            printf("\n");
        }
        //��� choice ���ç�Ѻ���͹����� ��������ͤ��� "Please try again."
        else{
            printf("\nPlease try again.\n\n");
        }
    }
}

//�ѧ���� addWithOrder �վ����������繾�µ����� head
struct Node* addWithOrder(struct Node* head){
    struct Node* l = (struct Node*)malloc(sizeof(struct Node)); //��С�Ⱦ�µ����� l �������ѧ�˹�����
    struct Node* tmp;   //��С�Ⱦ�µ�����  tmp

    //�Ѻ����繨ӹǹ��������㹵���� num
    int num;
    printf("Input Number: ");
    scanf("%d",&num);

    l->data = num;      //��˹��������µ�����  l ��ҡѺ num

    //��Ǩ�ͺ�ԧ����ʵ���ҧ ���� �˹������դ�ҹ��·���ش�������
    if(head == NULL || l->data <= head->data){
        l->link = head;     //����µ�����  l ���价�� head
        head = l;           //����µ�����  head ��ҡѺ��µ�����  l
    }
    else{
        tmp = head;     //����µ�����  tmp ��ҡѺ�˹� head

        //���͹䢷ӫ�����ͤ����˹�����ҡ�����˹�����
        while(tmp->link != NULL && tmp->link->data <= l->data){
            tmp = tmp->link;    //����µ�����  tmp �����˹�����
        }
        l->link = tmp->link;    //����˹�������价�����ǡѺ����˹� tmp ����
        tmp->link = l;          //����˹���� tmp �����仪����ѧ�˹� l
    }
    printf("Add [%d] Completed.\n",num);
    return head;    //�׹��� head
}

//�ѧ���� deleteHead �վ����������繾�µ����� head
struct Node* deleteHead(struct Node* head){
    //��Ǩ�ͺ�ԧ����ʵ���ҧ�������
    if(head == NULL){
        printf("This linked list is empty.\n");
    }
    else{
        printf("Delete [%d] Completed.\n",head->data);
        head = head->link;      //����µ����� head ��ҡѺ��µ����� head ��ǶѴ�
    }

    return head;    //�׹��� head
}

struct Node* deleteTail(struct Node* head){
    struct Node* tmp = head;    //��С�Ⱦ�µ�����  tmp ��ҡѺ��µ����� head

    //��Ǩ�ͺ�ԧ����ʵ���ҧ�������
    if(head == NULL){
        printf("This linked list is empty.\n");
    }
    else if(tmp->link == NULL){ //���������˹� ����������
        printf("Delete [%d] Completed.\n",tmp->data);
        head = NULL;    //����µ����� head ��ҡѺ�����ҧ
    }
    else{
        //���͹䢷ӫ����� ��µ����� tmp ��ǶѴ�� �����ҡѺ �����ҧ
        while(tmp->link->link != NULL){
            tmp = tmp->link;        //����͹��µ�������ѧ�˹��Ѵ�
        }
        printf("Delete [%d] Completed.\n",tmp->link->data);
        tmp->link = NULL;   //����µ����� tmp ��ǶѴ���ҡѺ�����ҧ
    }

    return head;    //�׹��� head
}

struct Node* deleteRequireNode(struct Node* head){
    struct Node* p;         //��С�Ⱦ�µ�����  p
    struct Node* tmp;       //��С�Ⱦ�µ�����  tmp
    int num;                //��С�ȵ���� num �繨ӹǹ���

    //��Ǩ�ͺ�ԧ����ʵ���ҧ�������
    if(head == NULL){
        printf("This linked list is empty.\n");
    }
    else{
        //�Ѻ��������㹵���� num
        printf("Input Number to Delete: ");
        scanf("%d",&num);

        tmp = head;     //����µ����� tmp ��ҡѺ��µ����� head

        //�ӫ�����ͤ��Ҥ�Ң����������˹�����դ����ҡѺ num
        while(tmp->data != num && tmp->link != NULL){
            p = tmp;            //����µ����� P �繾�µ�������Ǥ��Ǫ���� tmp
            tmp = tmp->link;    //����͹ tmp ��ѧ�˹��Ѵ�
        }
        //���͹䢶�Ҥ��� num �����
        if(tmp->data != num){
            printf("Node not found.\n");
        }
        else{
            //��Ǩ�ͺ�˹�����ͧ���ź���˹��á�������
            if(tmp == head){
            printf("Delete [%d] Completed.\n",tmp->data);
            head = tmp->link;   //����µ����� head ��ҡѺ��µ����� tmp ��ǶѴ�
        }
            else{
                printf("Delete [%d] Completed.\n",tmp->data);
                p->link = tmp->link;    //����µ����� p �����ѧ��µ����� tmp ��ǶѴ�
            }
        }
    }

    return head;
}

void displayLinklist(struct Node* head){
    //��С�Ⱦ�µ����� p ��������͹�㹡���ʴ���Ң����� � list
    struct Node* p = NULL;

    p = head; //��˹���������� p �����˹��á

    //���͹���Ҷ���ԧ����ʵ���ҧ
    if(p == NULL){
        printf("[]");
    }
    //��Ǩ�ͺ�ԧ����ʵ���ҧ�������
    while(p != NULL){
        //
        if(p->link != NULL){        //���͹���Ҿ�µ����� p ��ǶѴ����������ҧ
            printf("[%d]->",p->data);
        }
        else{
            printf("[%d]",p->data);
        }
        p = p->link;    //����µ����� p �����ѧ node ����
    }
    printf("\n");
}
