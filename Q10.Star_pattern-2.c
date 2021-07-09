#include <stdio.h>
int main()
{
    int i, j, n, x;
    printf("Enter the no of rows of the pattern (any odd natural number) : ");
    scanf("%d", &n);
    x = (n + 1) / 2;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= x)
            {

                if (j <= x - 1 + i && j >= x + 1 - i)
                    printf(" * ");
                else
                    printf("   ");
            }
            else
            {
                if (j == x)
                    printf(" * ");
                else
                    printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}
