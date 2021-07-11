#include <stdio.h>

//creat maximum function...
int maximum(int A[10][10], int i, int j, int row)
{
    int max = A[1][j];
    for (i = 1; i <= row; i++)
    {
        if (A[i][j] > max)
            max = A[i][j];
    }
    return max;
}

//creat minimum function...
int minimum(int B[10], int j, int column)
{
    int min = B[1];
    for (j = 1; j <= column; j++)
    {
        if (B[j] < min)
            min = B[j];
    }
    return min;
}
int main()
{
    int A[10][10], B[10];
    int row, column;
    int i, j, fA;
    printf("Enter row and column number of the 2-D array or Matrix :\n");
    scanf("%d%d", &row, &column);
    printf("Enter the elements of the matrix :\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= column; j++)
            scanf("%d", &A[i][j]);
    }
    printf("Your Matrix is :\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= column; j++)
        {
            printf("%4d\t", A[i][j]);
        }
        printf("\n");
    }
    //Calculate maximum element of each column...
    for (j = 1; j <= column; j++)
    {
        B[j] = maximum(A, i, j, row);
    }
    //Calculate minimum value of these maximum elements...
    fA = minimum(B, j, column);

    printf("Value of the function f(A) = min { max Aij} is : %d", fA);
    return 0;
}