#include<stdio.h>

void sum();

int main(){
    sum();
}

void sum(){
    int sum, num;

    do{
        printf("Input Number: ");
        scanf("%d",&num);
        sum += num;
    } while(num != 0);

    printf("Sum: %d", sum);
}
