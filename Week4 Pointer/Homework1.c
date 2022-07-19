#include <stdio.h>

void selectChoise();
void displayArray(int *ptr, int n);
void insertArray(int *ptr, int n);
void deleteArray(int *ptr, int n);

int main() {
    int arr[] = {-2, 0, 3, 11, 14, 16, 20, 22, 37, 53, 57, 66, 71};
    int *ptr = &arr[0];
    int n = sizeof(arr)/sizeof(arr[0]);
    selectChoise(ptr, n);
}

void selectChoise(int *ptr, int n){
    int choise = 1;

    while(choise != 0){
        printf("******Program array structure******\n");
        printf("1. Insert data in array structure in index\n");
        printf("2. Delete data in array structure\n");
        printf("3. Display data in array structure\n\n");

        printf("Type number [<= to select the option =>]: ");
        scanf("%d", &choise);

        if(choise == 1){
            n++;
            insertArray(ptr, n);
        }
        else if(choise == 2){
            n--;
            deleteArray(ptr, n);
        }
        else if(choise == 3){
            displayArray(ptr, n);
        }
    }
}

void insertArray(int *ptr, int n) {
    int pos, data;

    printf("Input position where you want: ");
    scanf("%d", &pos);
    printf("Input data if you want: ");
    scanf("%d", &data);

    for(int i=n-1;i>=pos;i--){
        //arr[i+1] = arr[i];
        *(ptr+i+1) = *(ptr+i);
    }

    //arr[pos] = data;
    *(ptr+pos) = data;
    displayArray(ptr, n);
}

void deleteArray(int *ptr, int n){
    int pos, data;

    printf("Input position where you want to delete: ");
    scanf("%d", &pos);

    for(int i=pos-1;i<n;i++){
        *(ptr+i) = *(ptr+i+1);
        //arr[i] = arr[i+1];
    }

    displayArray(ptr, n);
}

void displayArray(int *ptr, int n) {
    //printf("%d ", n);
    for(int i=0;i<n;i++){
        printf("[%d] ", *(ptr+i));
    }
    printf("\n\n");
}
