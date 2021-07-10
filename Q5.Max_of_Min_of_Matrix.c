#include <stdio.h>

//creat minimum function...
int minimum(int A[10][10], int i, int j, int column)
{
    int min = A[i][1];
    for (j = 1; j <= column; j++)
    {
        if (A[i][j] < min)
            min = A[i][j];
    }
    return min;
}

//creat maximum function...
int maximum(int B[10], int i, int row)
{
    int max = B[1];
    for (i = 1; i <= row; i++)
    {
        if (B[i] > max)
            max = B[i];
    }
    return max;
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
    //Calculate minimum element of each row...
    for (i = 1; i <= row; i++)
    {
        B[i] = minimum(A, i, j, column);
    }
    //Calculate maximum value of these minimum elements...
    fA = maximum(B, i, row);

    printf("Value of the function f(A) = max { min Aij} is : %d", fA);
    return 0;
}