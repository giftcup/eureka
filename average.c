#include <stdio.h>

int main()
{
    int numOfNums, i = 0;
    double numbers[50], sum = 0.0;
    double average;

    do 
    {
        printf("Enter the number of elements not more than fifty: ");
        scanf("%d", &numOfNums);
    }while(numOfNums > 50 || numOfNums < 1);

    while (i < numOfNums)
    {
        printf("%d. Number: ", i+1);
        scanf("%lf", &numbers[i]);
        sum += numbers[i];
        i++;
    }
    average = sum / numOfNums;
    printf("Average = %.2lf\n", average);

    return 0;
}