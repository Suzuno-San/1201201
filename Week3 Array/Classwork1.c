#include <stdio.h>
void insertArray(int arr[],int p,int data);
void displayArray(int arr[]);
void main(){

    int arr[10];
    int p;
    int data;

    insertArray(arr, p, data);
}
void insertArray(int arr[],int p,int data){
    for(int i=0;i<10;i++)
        arr[i]=(i+1)*8;
    displayArray (arr);

    printf("insert position :");
    scanf("%d",&p);
    printf("insert number :");
    scanf("%d",&data);

    for(int i=9;i>p;i--){
        arr[i]=arr[i-1];
    }
    arr[p]=data;
    displayArray (arr);

}


void displayArray(int arr[]){
    for(int i=0;i<10;i++){
        printf("address of data[%d] is %d, \n",i,arr[i]);

    }
    }
