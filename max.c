#include <stdio.h>

int main()
{
    int numOfNums, i = 0;
    double numbers[100];
    
    do
    {
        printf("Enter the number of numbers: ");
        scanf("%d", &numOfNums);
    } while (numOfNums > 100 || numOfNums < 1);

    while (i < numOfNums)
    {
        printf("%d number: ", i+1);
        scanf("%lf", &numbers[i]);
        i++;
    }
    
    for (i = 1; i < numOfNums; i++)
    {
        if(numbers[i] > numbers[0])
        {
            numbers[0] = numbers[i];
        }
    }
    printf("Largest element = %.2lf\n", numbers[0]);
    return 0;
}