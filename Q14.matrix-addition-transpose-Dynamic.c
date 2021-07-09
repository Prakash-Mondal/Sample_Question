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
void **output_array(int **a, int a_row, int a_column)
{
    int i, j;
    for (i = 0; i < a_row; i++)
    {
        for (j = 0; j < a_column; j++)
        {
            printf("%4d\t", a[i][j]);
        }
        printf("\n");
    }
}
// Add = a + b   addition function...
int **addition_array(int **a, int **b, int a_row, int a_column)
{
    int i, j;
    int **Add;
    Add = (int **)malloc(sizeof(int *) * a_row);
    for (i = 0; i < a_row; i++)
    {
        Add[i] = malloc(sizeof(int *) * a_column);
    }
    for (i = 0; i < a_row; i++)
    {
        for (j = 0; j < a_column; j++)
        {
            Add[i][j] = a[i][j] + b[i][j];
        }
    }
    return Add;
}

//Tranpose function...
void **transpose(int **Add, int a_row, int a_column)
{
    int i, j;
    for (i = 0; i < a_column; i++)
    {
        for (j = 0; j < a_row; j++)
        {
            printf("%4d\t", Add[j][i]);
        }
        printf("\n");
    }
}

//Main program
int main()
{
    int i, j, temp = 0;
    int a_row, a_column;
    int b_row, b_column;

    int **a, **b, **Add, **d, **e;
    //Array a
    printf("Please enter the row and column number of First matrix :\n");
    scanf("%d %d", &a_row, &a_column);
    //Array b
    printf("Please enter the row and column number of second matrix :\n");
    scanf("%d %d", &b_row, &b_column);
    //Condition Check.
    if ((a_row == b_row) && (a_column == b_column))
    {
        //Taking inputs of the arrays...
        printf("Please enter the elements of First matrix :\n");
        a = input_array(a_row, a_column);
        printf("Please enter the elements of second matrix :\n");
        b = input_array(b_row, b_column);

        //Printing the matrices...
        printf("\nFirst matrix is :\n");
        output_array(a, a_row, a_column);
        printf("\nSecond matrix is :\n");
        output_array(b, b_row, b_column);

        //Add function call...
        printf("\nAddition result is :\n");
        Add = addition_array(a, b, a_row, a_column);
        output_array(Add, a_row, a_column);

        //Transpose function call...
        printf("\nTranspose of the resultant matrix is :\n");
        transpose(Add, a_row, a_column);
    }

    else
        printf("\nMatrix addition not possible.\n");

    // Free the memory...
    for (i = 0; i < a_column; i++)
    {
        free(a[i]);
        free(b[i]);
        free(Add[i]);
    }
    free(a);
    free(b);
    free(Add);

    return 0;
}