//���¡�� .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //�红�����
    struct Node *link;  //��ʶҹ���ͧ�˹��Ѵ�
};

void deleteRequireNode(struct Node** head);
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
    deleteRequireNode(&head);
    printf("\nAfter ");
    display(head);
}

void deleteRequireNode(struct Node** head){
    struct Node* p;             //��С�Ⱦ������ p
    struct Node* tmp = *head;   //��С�Ⱦ������ tmp ��ҡѺ head

    //�Ѻ��� ���乵���� num
    int num;
    printf("Input value to delete: ");
    scanf("%d",&num);

    //��� linkedlist �繤����ҧ
    if(*head == NULL){
        printf("Linkedlist is empty.");
    }
    else{
        //���͹䢷ӫ�� ��� tmp �����ҡѺ num ��� �˹��Ѵ�����繤����ҧ
        while(tmp->data != num && tmp->link != NULL){
            p = tmp;            //������� p ��ҡѺ������� tmp
            tmp = tmp->link;    //����͹��˹��Ѵ�
        }
        //������� tmp �դ�������ҡѺ num
        if(tmp->data != num){
            printf("Node not found.\n");
        }
        else{
            //��� tmp ��ҡѺ head
            if(tmp == *head){
                *head = tmp->link;  //��� head ��ҡѺ �˹��Ѵ�
            }
            else{
                p->link = tmp->link;    //������� p �����˹��Ѵ仢ͧ������� tmp
            }
        }
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



