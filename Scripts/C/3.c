//Write a recursive program in C to find the GCD of two integer numbers
#include <stdio.h>

int GCD(int x, int y){
    if(y!=0)
        return GCD(y, x%y);
    else
        return x;
}

int main(){
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("GCD of given numbers: %d", GCD(num1, num2));

    return 0;
}