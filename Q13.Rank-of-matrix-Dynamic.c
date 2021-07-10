#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int i, j;
    int **A;
    A = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++)
    {
        A[i] = malloc(3 * sizeof(int));
    }

    printf("Enter the values of a 3*3 Matrix :\n");

    int flag = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
            if (A[i][j] > flag)
                flag = 1;
        }
    }
    printf("\nRank of the matrix is : ");
    if (flag == 0)
    {
        printf("0");
    }
    else
    {
        int d = A[0][0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2]) - A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) + A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);
        if (d != 0)
        {
            printf("3");
        }
        else
        {
            int deter = A[0][0] * A[1][1] - A[1][0] * A[0][1];
            if (deter != 0)
            {
                printf("2");
            }
            else
            {
                int deter1 = A[1][0] * A[2][1] - A[2][0] * A[1][1];
                if (deter1 != 0)
                {
                    printf("2");
                }
                int deter2 = A[0][1] * A[1][2] - A[1][1] * A[0][2];
                if (deter2 != 0)
                {
                    printf("2");
                }
                int deter3 = A[2][2] * A[1][1] - A[2][1] * A[1][2];
                if (deter3 != 0)
                {
                    printf("2");
                }
                else
                    printf("1");
            }
        }
    }

    // Free the memory...
    for (i = 0; i < 10; i++)
    {
        free(A[i]);
    }
    free(A);

    return 0;
}