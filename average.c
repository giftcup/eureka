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
    // repeats the loop until the number of elements 
    // doesn't exceed the size of the array used in storing numbers.

    while (i < numOfNums)
    {
        printf("%d. Number: ", i+1);
        scanf("%lf", &numbers[i]); //stores the numbers read in the array.
        sum += numbers[i]; // adds the number read to the sum
        i++;
    }
    average = sum / numOfNums; // Calculates the average
    printf("Average = %.2lf\n", average); //prints out the calculated average to 2d.p

    return 0;
}