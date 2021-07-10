/* Find Rank of a Matrix */
/* RANK.C */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int R, C;
int i, j;

void display(int **, int, int);
void input(int **, int, int);
int Rank_Mat(int **, int, int);
void swap(int **, int, int, int);

/* This function exchange two rows of a matrix */

void swap(int **mat, int row1, int row2, int col)
{
    for (i = 0; i < col; i++)
    {
        int temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

/* This function find rank of matrix */

int Rank_Mat(int **mat, int row1, int col1)
{
    int r, c;
    for (r = 0; r < col1; r++)
    {
        display(mat, R, C);
        printf("\n");
        if (mat[r][r]) // Diagonal element is not zero
        {
            for (c = 0; c < row1; c++)
                if (c != r)
                {
                    /* Make all the elements above and below the current principal
                 diagonal element zero */

                    double ratio = mat[c][r] / mat[r][r];
                    for (i = 0; i < col1; i++)
                        mat[c][i] -= ratio * mat[r][i];
                }
        }

        /* Principal Diagonal elment is zero */

        else
        {
            for (c = r + 1; c < row1; c++)
                if (mat[c][r])
                {
                    /*  Find non zero elements in the same column */
                    swap(mat, r, c, col1);
                    break;
                }

            if (c == row1)
            {
                --col1;

                for (c = 0; c < row1; c++)
                    mat[c][r] = mat[c][col1];
            }
            --r;
        }
    }
    return col1;
}

/* Output function */

void display(int **mat, int row, int col)
{
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

/* Input function */

void input(int **mat, int row, int col)
{
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf(" Enter Value for position of mat[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

/* main function */

int main()
{

    int rank;
    printf("\n Enter number of rows : ");
    scanf("%d", &R);
    printf(" Enter number of columns : ");
    scanf("%d", &C);
    printf("\n");

    int **mat;
    mat = (int **)malloc(sizeof(int *) * R);

    for (i = 0; i < R; i++)
        mat[i] = (int *)malloc(sizeof(int) * C);

    input(mat, R, C);
    printf("\n Row of the matrix is : %d", R);
    printf("\n Column of the matrix is : %d \n", C);

    printf("\n Your matrix is as follows:\n\n");
    display(mat, R, C);

    //Calculating the rank of the matrix ....

    printf("\n Row reduced operations are as follows :\n\n");
    rank = Rank_Mat(mat, R, C);
    printf(" Rank of the above matrix is : %d\n\n", rank);

    // Free the memory...
    for (i = 0; i < C; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return 0;
}