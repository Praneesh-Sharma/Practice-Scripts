//Write a recursive program in C to print percentages from 1% to 50% of a integer number. User will ask to enter a number.
#include<stdio.h>

void recursion(int i,float n){
    if(i>50)
        return;
    else
        printf("%d %% = %0.2f \n",i,(n*i)/100);
    recursion(i=i+1,n);
}


int main()
{
 float num;
 printf("Enter number: ");
 scanf("%f",&num);
 recursion(1,num);

 return 0;
}