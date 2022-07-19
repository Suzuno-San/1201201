#include<stdio.h>

void sum();

int main() {
    sum();

    return 0;
}

void sum() {
    int sum, num=1;

    while(num != 0){
        printf("Input Number: ");
        scanf("%d",&num);
        sum += num;
    }

    printf("Sum: %d",sum);
}
