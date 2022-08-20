//���¡�� .h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;           //�红�����
    struct Node *link;  //��ʶҹ���ͧ�˹��Ѵ�
};

//��С�� function
void menu(struct Node* head);
void addHead(struct Node** head);
void addTail(struct Node** head);
void addWithOrder(struct Node** head);
void deleteHead(struct Node** head);
void deleteTail(struct Node** head);
void deleteRequireNode(struct Node** head);
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
        printf("1. Add head\n");
        printf("2. Add tail\n");
        printf("3. Add with order\n");
        printf("4. Delete head\n");
        printf("5. Delete tail\n");
        printf("6. Delete requireNode\n");
        printf("7. Display\n\n");

        printf("Type number [<= to select the option =>]: ");
        scanf("%d", &choice);

        //��� choice ��ҡѺ 0 ������ͤ��� "Good Bye."
        if(choice == 0){
            printf("\nGood Bye.\n");
        }

        //��� choice ��ҡѺ 1 ������¡�ѧ��ѹ������ҧ˹��
        else if(choice == 1){
            printf("\n");
            addHead(&head);
            printf("\n");
        }

        //��� choice ��ҡѺ 2 ������¡�ѧ��ѹ������ҧ��ѧ
        else if(choice == 2){
            printf("\n");
            addTail(&head);
            printf("\n");
        }

        //��� choice ��ҡѺ 3 ������¡�ѧ��ѹ����Ẻ�ӴѺ
        else if(choice == 3){
            printf("\n");
            addWithOrder(&head);
            printf("\n");
        }

        //��� choice ��ҡѺ 2 ������¡�ѧ��ѹź��ǹ���
        else if(choice == 4){
            printf("\n");
            deleteHead(&head);
            printf("\n");
        }

        //��� choice ��ҡѺ 3 ������¡�ѧ��ѹź��ǹ����
        else if(choice == 5){
            printf("\n");
            deleteTail(&head);
            printf("\n");
        }

        //��� choice ��ҡѺ 4 ������¡�ѧ��ѹź��Ƿ���ͧ���
        else if(choice == 6){
            printf("\n");
            deleteRequireNode(&head);
            printf("\n");
        }

        //��� choice ��ҡѺ 5 ������¡�ѧ��ѹ�ʴ�������� linkedlist
        else if(choice == 7){
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

void addHead(struct Node** head){
    struct Node* l = (struct Node*)malloc(sizeof(struct Node));     //��С���˹�����

    //�Ѻ��Ң�������������˹�����
    int num;
    printf("Input value to add: ");
    scanf("%d",&num);
    l->data = num;

    l->link = *head;     //����˹���������ѧ�˹���� head ����
    *head = l;           //��� head �����ѧ�˹� l

    printf("Add [%d] Completed.\n",num);
}

void addTail(struct Node** head){
    struct Node* l = (struct Node*)malloc(sizeof(struct Node));     //��С���˹�����
    struct Node* p = *head;
    struct Node* last;

    //�Ѻ��Ң�������������˹�����
    int num;
    printf("Input value to add: ");
    scanf("%d",&num);
    l->data = num;

    //��������� l ���� Null
    l->link = NULL;

    //��Ǩ�ͺ�ԧ����ʵ���ҧ�������
    if(*head == NULL){
        l->link = *head;     //��� l ���� head
        *head = l;           //��������� head ��ҡѺ ��µ����� l
    }
    else{
        //���͹���Ҿ�µ����� p ��������ҡѺ�����ҧ�������
        while(p->link != NULL){
            p = p->link;    //����µ����� p ��ѧ�˹�����
            last = p;       //����µ����� last ��ҡѺ������� p
        }
        last->link = l;        //����µ����� last ���仾�µ����� l
    }
    printf("Add [%d] Completed.\n",num);
}

//�ѧ���� addWithOrder �վ����������繾�µ����� head
void addWithOrder(struct Node** head){
    struct Node* l = (struct Node*)malloc(sizeof(struct Node)); //��С�Ⱦ�µ����� l �������ѧ�˹�����
    struct Node* tmp;   //��С�Ⱦ�µ�����  tmp

    //�Ѻ����繨ӹǹ��������㹵���� num
    int num;
    printf("Input value to add: ");
    scanf("%d",&num);

    l->data = num;      //��˹��������µ�����  l ��ҡѺ num

    //��Ǩ�ͺ�ԧ����ʵ���ҧ ���� �˹������դ�ҹ��·���ش�������
    if(*head == NULL || l->data <= (*head)->data){
        l->link = *head;     //����µ�����  l ���价�� head
        *head = l;           //����µ�����  head ��ҡѺ��µ�����  l
    }
    else{
        tmp = *head;         //����µ�����  tmp ��ҡѺ��µ����� head

        //���͹䢷ӫ�����ͤ����˹�����ҡ�����˹�����
        while(tmp->link != NULL && tmp->link->data <= l->data){
            tmp = tmp->link;    //����µ�����  tmp �����˹�����
        }
        l->link = tmp->link;    //����˹�������价�����ǡѺ����˹� tmp ����
        tmp->link = l;          //����˹���� tmp �����仪����ѧ�˹� l
    }
    printf("Add [%d] Completed.\n",num);
}

//�ѧ���� deleteHead �վ����������繾�µ����� head
void deleteHead(struct Node** head){
    //��Ǩ�ͺ�ԧ����ʵ���ҧ�������
    if(*head == NULL){
        printf("This linked list is empty.\n");
    }
    else{
        printf("Delete [%d] Completed.\n",(*head)->data);
        *head = (*head)->link;      //����µ����� head ��ҡѺ��µ����� head ��ǶѴ�
    }
}

void deleteTail(struct Node** head){
    struct Node* tmp = *head;    //��С�Ⱦ�µ�����  tmp ��ҡѺ��µ����� head

    //��Ǩ�ͺ�ԧ����ʵ���ҧ�������
    if(*head == NULL){
        printf("This linked list is empty.\n");
    }
    else if(tmp->link == NULL){ //���������˹� ����������
        printf("Delete [%d] Completed.\n",tmp->data);
        *head = NULL;    //����µ����� head ��ҡѺ�����ҧ
    }
    else{
        //���͹䢷ӫ����� ��µ����� tmp ��ǶѴ�� �����ҡѺ �����ҧ
        while(tmp->link->link != NULL){
            tmp = tmp->link;        //����͹��µ�������ѧ�˹��Ѵ�
        }
        printf("Delete [%d] Completed.\n",tmp->link->data);
        tmp->link = NULL;   //����µ����� tmp ��ǶѴ���ҡѺ�����ҧ
    }
}

void deleteRequireNode(struct Node** head){
    struct Node* p;         //��С�Ⱦ�µ�����  p
    struct Node* tmp;       //��С�Ⱦ�µ�����  tmp
    int num;                //��С�ȵ���� num �繨ӹǹ���

    //��Ǩ�ͺ�ԧ����ʵ���ҧ�������
    if(*head == NULL){
        printf("This linked list is empty.\n");
    }
    else{
        //�Ѻ��������㹵���� num
        printf("Input value to delete: ");
        scanf("%d",&num);

        tmp = *head;     //����µ����� tmp ��ҡѺ��µ����� head

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
            if(tmp == *head){
            printf("Delete [%d] Completed.\n",tmp->data);
            *head = tmp->link;   //����µ����� head ��ҡѺ��µ����� tmp ��ǶѴ�
        }
            else{
                printf("Delete [%d] Completed.\n",tmp->data);
                p->link = tmp->link;    //����µ����� p �����ѧ��µ����� tmp ��ǶѴ�
            }
        }
    }
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

