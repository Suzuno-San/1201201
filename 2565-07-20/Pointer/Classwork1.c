#include <stdio.h>
void insertArray(int *ptr,int p,int data);
void displayArray(int *ptr);
void main(){

    int arr[10];
    int *ptr = &arr[0];
    int p;
    int data;

    insertArray(ptr, p, data);
}
void insertArray(int *ptr,int p,int data){
    for(int i=0;i<10;i++)
        //arr[i]=(i+1)*8;
        *(ptr+i) = (i+1)*8;
    displayArray (ptr);

    printf("insert position :");
    scanf("%d",&p);
    printf("insert number :");
    scanf("%d",&data);

    for(int i=9;i>p;i--){
        //arr[i]=arr[i-1];
        *(ptr+i)=*((ptr+i)-1);
    }
    //arr[p]=data;
    *(ptr+p) = data;
    displayArray (ptr);

}


void displayArray(int *ptr){
    for(int i=0;i<10;i++){
        printf("address of data[%d] is %d, \n",i,*(ptr+i));

    }
}

