#include <stdio.h>

//creat maximum function...
int maximum(int A[10][10], int i, int j, int column)
{
    int max = A[i][1];
    for (j = 1; j <= column; j++)
    {
        if (A[i][j] > max)
            max = A[i][j];
    }
    return max;
}

//creat minimum function...
int minimum(int B[10], int i, int row)
{
    int min = B[1];
    for (i = 1; i <= row; i++)
    {
        if (B[i] < min)
            min = B[i];
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
    //Calculate maximum element of each row...
    for (i = 1; i <= row; i++)
    {
        B[i] = maximum(A, i, j, column);
    }
    //Calculate minimum value of these maximum elements...
    fA = minimum(B, i, row);

    printf("Value of the function f(A) = min { max Aij} is : %d", fA);
    return 0;
}