#include <stdio.h>

void selectChoise();
void displayArray(int arr[], int n);
void insertArray(int arr[], int n);
void deleteArray(int arr[], int n);
void searchArray(int arr[], int n);

int main() {
    int arr[] = {-2, 0, 3, 11, 14, 16, 20, 22, 37, 53, 57, 66, 71};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectChoise(arr, n);
}

void selectChoise(int arr[], int n){
    int choise = 1;

    while(choise != 0){
        printf("******Program array structure******\n");
        printf("1. Insert data in array structure in index\n");
        printf("2. Delete data in array structure\n");
        printf("3. Search data in array structure\n");
        printf("4. Display data in array structure\n\n");

        printf("Type number [<= to select the option =>]: ");
        scanf("%d", &choise);

        if(choise == 1){
            n++;
            insertArray(arr, n);
        }
        else if(choise == 2){
            n--;
            deleteArray(arr, n);
        }
        else if(choise == 3){
            searchArray(arr, n);
        }
        else if(choise == 4){
            displayArray(arr, n);
        }
    }
}

void insertArray(int arr[], int n) {
    int pos, data;

    printf("Input position where you want: ");
    scanf("%d", &pos);
    printf("Input data if you want: ");
    scanf("%d", &data);

    for(int i=n-1;i>=pos;i--){
        arr[i+1] = arr[i];
    }

    arr[pos] = data;
    displayArray(arr, n);
}

void deleteArray(int arr[], int n){
    int pos, data;

    printf("Input position where you want to delete: ");
    scanf("%d", &pos);

    for(int i=pos;i<n;i++){
        arr[i] = arr[i+1];
    }

    displayArray(arr, n);
}

void searchArray(int arr[], int n) {
    int pos, data;

    printf("Input data if you want to search: ");
    scanf("%d", &data);

    for(int i=0;i<n;i++){
        if(arr[i] == data){
            printf("%d is found at index %d\n",data, i);
            displayArray(arr, n);
            break;
        }
        else if(i==n-1){
            printf("Not found.\n");
        }
    }
}

void displayArray(int arr[], int n) {
    for(int i=0;i<n;i++){
        printf("[%d] ", arr[i]);
    }
    printf("\n\n");
}
