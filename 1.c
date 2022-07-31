/* WAP to find the largest number and count the occurrence of the largest number in an
array of n integers using a single loop. */

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int largest = array[0], count = 0;
    for (int i = 1; i < n; i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
            count = 0;
        }
        if (array[i] == largest)
        {
            count++;
        }
    }
    printf("Largest : %d\n",largest);
    printf("Occurence : %d",count);
    return 0;
}