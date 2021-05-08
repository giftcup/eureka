/*A program that receives two square matrices and performs
*basic operations of addition and division on the where compatible.
*It also computes the trace of each matrix.
**/

#include <stdio.h>

void displayNumbers(int num[100][100], int n); //Displays matrix.
int trace(int num[100][100], int a); //Computes the trace.
void sum(int m, int mat1[100][100], int mat2[100][100]); //Computes the sum.
void prod(int m, int mat1[100][100], int mat2[100][100]); //Computes the product

int num[100][100];

int main()
{
    int n, m;
    /*First square matrix of size "n" and
    *second of size "m". 
    */
    int trace1, trace2;
    int mat1[100][100], mat2[100][100];
    
    printf("Enter the size of your first square matrix: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n*n);  //Inputting numbers into the matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    displayNumbers(mat1, n); //function to display the matrix
    
    trace1 = trace(mat1, n); //function to calculate the trace of a matrix
    printf("The trace is %d\n", trace1);
    
    printf("Enter the size of your second square matrix: ");
    scanf("%d", &m);
    
    printf("Enter %d numbers:\n", m*m);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
                scanf("%d", &mat2[i][j]);
        }
    }
    displayNumbers(mat2, m);

    trace2 = trace(mat2, m);
    printf("The trace is %d\n", trace2);

    if(n == m)
    {
        sum(m, mat1, mat2);
        prod(m, mat1, mat2);
    }
     else
    {
        printf("Addition and multiplication are not compatible\n");
    }
    
    return 0;
}


void displayNumbers(int num[100][100], int a) //Displays each matrix;
{
    printf("Displaying:\n");
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < a; ++j)
        {
            printf("%d", num[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

int trace(int num[100][100], int a) //Calculating the trace of each matrix;
{
    int trace = 0;
    for(int i=0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if(i == j)
                trace += num[i][j];
        }
    }
    return trace;
}

void sum(int m, int mat1[100][100], int mat2[100][100]) //Adding two matrices
{
    int sum[100][100];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }       
    }
    printf("Sum ");
    displayNumbers(sum, m);
}

void prod(int m, int mat1[100][100], int mat2[100][100]) //Multiplying two matrices
{
    int prod[100][100];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
                prod[i][j] = 0;
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < m; k++)
            {
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }       
    }
    printf("Product ");
    displayNumbers(prod, m);
}