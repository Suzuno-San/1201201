//���¡�� .h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;           //�红�����
    struct Node *link;  //��ʶҹ���ͧnode�Ѵ�
};

//��С�� function
int countelementlist(struct Node* head);
bool searchlistlist(struct Node* head, int key);
void displaylinklist(struct Node* head);

void main(){
    //��С�ȵ�����������ҧ node
    struct Node *head;      //��С�ȵ���� head ��  pointer ������ʶҹ���ͧnode�á
    struct Node *first;     //��С�ȵ���� first
    struct Node *second;    //��С�ȵ���� second
    struct Node *third;     //��С�ȵ���� third

    //�ͧ��. �˹��¤�����
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //��˹��������� node
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

    //���¡�� function displaylinklist �����ʴ���Ң������ list
    displaylinklist(head);

    //���¡�� function countelementlist �����㹵���� count �纨ӹǹ������� list ����ʴ�����͡��
    int count = countelementlist(head);
    printf("Count of LinkList is %d\n",count);

    //�Ѻ��� key
    int key;
    printf("\nInput Key for Search: ");
    scanf("%d",&key);

    //���¡�� function searchlistlist �纤�ҷ�� return ���㹵���� found
    bool found = searchlistlist(head,key);
    if(found == true){                              //��� found �դ����ҡѺ true ������� Found
        printf("%d Found in LinkedList\n",key);
    }
    else{                                           //���  found �դ����ҡѺ false ������� Not Found
        printf("%d Not Found in LinkedList\n",key);
    }
}

//�ѧ��ѹ�Ѻ�ӹǹ elementlist
int countelementlist(struct Node* head){
    //��С�ȵ���þ�µ����� p ��������͹�㹡���ʴ���Ң����� � list
    struct Node* p = NULL;

    p = head;           //��� p ��ҡѺ head
    int count;          //��С�ȵ���� count �繨ӹǹ���
    printf("\n");
    while(p != NULL){   //���͹䢡�÷ӫ�� �������͹� p �����ҡѺ�����ҧ
        count++;        //��� count ������� 1
        p = p->link;    //����µ����� p �����ѧ node ����
    }

    return count;      //�׹��� count
}

//�ѧ��ѹ���� elementlist
bool searchlistlist(struct Node* head,int key){
    //��С�ȵ���þ�µ����� p ��������͹�㹡���ʴ���Ң����� � list
    struct Node* p = NULL;

    p = head;                   //��� p ��ҡѺ head
    bool found = false;         //��С�ȵ���� found �� boolean �դ������
    while((p != NULL)&&(found != true)){    //���͹䢡�÷ӫ�� �������͹� p �����ҡѺ�����ҧ ��� found ����繨�ԧ
        if(p->data == key){     //���͹���� ������� node p �դ����� key
            found = true;       //��� found �繨�ԧ
        }
        p = p->link;            //����µ����� p �����ѧ node ����
    }
    return found;       //�׹��� found
}

void displaylinklist(struct Node* head){
    //��С�� pointer p ��������͹�㹡���ʴ���Ң����� � list
    struct Node* p = NULL;

    p = head;                           //��˹���� pointer p ���� node �á
    printf("\n");
    while(p != NULL){                   //���͹䢡�÷ӫ�� �������͹� p �����ҡѺ�����ҧ
        if(p->link != NULL){            //���͹���� link � node p ���ç�Ѻ�����ҧ
            printf("[%d]->",p->data);
        }
        else{
            printf("[%d]",p->data);
        }
        p = p->link;        //����µ����� p �����ѧ node ����
    }
    printf("\n");
}
