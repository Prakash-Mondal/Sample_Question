#include <stdio.h>
#include <stdlib.h>
//Initialize the dynamic array
int **input_array(int a_row, int a_column)
{
    int i, j;

    int **a;

    a = (int **)malloc(sizeof(int *) * a_row);

    for (i = 0; i < a_row; i++)
        *(a + i) = (int *)malloc(sizeof(int) * a_column);

    for (i = 0; i < a_row; i++)
        for (j = 0; j < a_column; j++)
            scanf("%d", *(a + i) + j); //Can also be written as &a[i][i], pay attention to distinguish the difference between *(a+i)+j and *(*(a+i)+j)
    return a;
}

//Output matrix
int **output_array(int **a, int a_row, int a_column)
{
    int i, j;
    int **N;
    N = (int **)malloc(sizeof(int *) * a_row);
    for (i = 0; i < a_row; i++)
    {
        N[i] = malloc(sizeof(int *) * a_column);
    }

    for (i = 0; i < a_row; i++)
    {
        for (j = 0; j < a_column; j++)
        {

            printf("%4d\t", a[i][j]);
            N[i][j] = a[i][j];
        }
        printf("\n");
    }
    return N;
}
// c = a * b   multiplication function...
int **multiply_array(int **a, int **b, int a_row, int a_column, int b_row, int b_column)
{
    int i, j, k, total;
    int **M;
    M = (int **)malloc(sizeof(int *) * a_row);
    for (i = 0; i < a_row; i++)
    {
        M[i] = malloc(sizeof(int *) * b_column);
    }
    for (i = 0; i < a_row; i++)
    {
        for (j = 0; j < b_column; j++)
        {
            total = 0;
            for (k = 0; k < a_column; k++)
            {
                total = (total + (a[i][k] * b[k][j]));
                M[i][j] = total;
            }
        }
    }
    return M;
}

int check_idempotent(int **e, int **c, int a_row, int b_column)
{
    int i, j;
    for (i = 0; i < a_row; i++)
    {
        for (j = 0; j < b_column; j++)
        {
            if (e[i][j] != c[i][j])
                return 1;
        }
    }
    return 0;
}
//Main program
int main()
{
    int i, j, temp = 0;
    int a_row, a_column;
    int b_row, b_column;

    int **a, **b, **c, **d, **e;
    //Array a
    printf("Please enter the row and column number of First matrix :\n");
    scanf("%d %d", &a_row, &a_column);
    //Array b
    printf("Please enter the row and column number of second matrix :\n");
    scanf("%d %d", &b_row, &b_column);
    //Condition Check.
    if (a_column == b_row)
    {
        //Taking inputs of the arrays...
        printf("Please enter the elements of First matrix :\n");
        a = input_array(a_row, a_column);
        printf("Please enter the elements of second matrix :\n");
        b = input_array(b_row, b_column);

        //Printing the matrices...
        printf("\nFirst matrix is :\n");
        for (i = 0; i < a_row; i++)
        {
            for (j = 0; j < a_column; j++)
            {
                printf("%4d\t", a[i][j]);
            }
            printf("\n");
        }
        printf("\nSecond matrix is :\n");
        for (i = 0; i < b_row; i++)
        {
            for (j = 0; j < b_column; j++)
            {
                printf("%4d\t", b[i][j]);
            }
            printf("\n");
        }

        //Array c
        printf("\nMultiplication result is :\n");
        c = multiply_array(a, b, a_row, a_column, b_row, b_column);
        d = output_array(c, a_row, b_column);
        printf("\nSquare of resultant matrix is :\n");
        e = multiply_array(c, d, a_row, b_column, a_row, b_column);
        output_array(e, a_row, b_column);
        temp = check_idempotent(e, c, a_row, b_column);

        if (temp == 1)
            printf("\nResultant matrix is not idempotent.\n");
        else
            printf("\nResultant matrix is idempotent.\n");
    }
    else
        printf("\nMatrix multiplication not possible.\n");
    return 0;
}
