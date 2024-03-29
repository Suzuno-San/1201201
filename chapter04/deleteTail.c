//���¡�� .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //�红�����
    struct Node *link;  //��ʶҹ���ͧ�˹��Ѵ�
};

void deleteTail(struct Node** head);
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
    deleteTail(&head);
    printf("\nAfter ");
    display(head);
}

void deleteTail(struct Node** head){
    struct Node *p = *head;     //��������� p ��ҡѺ������� head

    //��� linkedlist �繤����ҧ
    if(*head == NULL){
        printf("Linkedlist is empty.");
    }
    else{
        //���͹䢷ӫ������˹��ͧ�����Ѵ����繤����ҧ
        while(p->link->link != NULL){
            p = p->link;    //����͹��˹��Ѵ�
        }
        p->link = NULL;     //��������� p ���令����ҧ
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


