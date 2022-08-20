#include<stdio.h>

void sum();

int main() {
    sum();

    return 0;
}

void sum(){
    int sum, num=1;

    for(int i=1;num!=0;i++){
        printf("Input Number: ");
        scanf("%d",&num);
        sum += num;
    }

    printf("Sum: %d", sum);
}
