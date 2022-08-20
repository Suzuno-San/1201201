//���¡�� .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //�红�����
    struct Node *link;  //��ʶҹ���ͧ�˹��Ѵ�
};

void addWithOrder(struct Node** head);
void display(struct Node* head);

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

    //���¡�ѧ��ѹ
    printf("Before ");
    display(head);
    printf("\n");
    addWithOrder(&head);
    printf("\nAfter ");
    display(head);
}

void addWithOrder(struct Node** head){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));   //���ҧ�˹�������Шͧ��. � memory
    struct Node *p = *head;     //��С�Ⱦ������ p ��ҡѺ������� head

    //�Ѻ��������������������
    int num;
    printf("Input value to add with order: ");
    scanf("%d",&num);

    newnode->data = num;
    newnode->link = NULL;

    //���͹���Ҷ�� linkedlist �繤����ҧ ���� �˹������դ�ҹ��·���ش
    if(*head == NULL || (*head)->data >= newnode->data){
        newnode->link = *head;  //����˹�������价�������� head
        *head = newnode;        //��������� head ��ҡѺ�˹�����
    }
    else{
        //���͹䢷ӫ����� �˹��������������ҧ ��� �˹��Ѵ��դ�� ���¡���������ҡѺ �˹�����
        while(p->link != NULL && p->link->data <= newnode->data){
            p = p->link;    //��˹��Ѵ�
        }
        newnode->link = p->link;    //�˹�������价�� �˹��Ѵ仢ͧ������� p
        p->link = newnode;          //������� p ���价���˹�����
    }
}

void display(struct Node* head){
    struct Node *p = head;  //���ҧ������� p ��ҡѺ������� head

    //�ʴ����� linkedlist
    while(p != NULL){
        printf("[%d] ",p->data);
        p = p->link;
    }
}


