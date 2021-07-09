#include <stdio.h>
int nCr(int, int);
int main()
{
    int i, j, n, r;
    printf("Enter the number of rows : ");
    scanf("%d", &n);
    printf("\n");
    for (i = n; i >= 1; i--)
    {
        r = 0;
        for (j = 1; j <= n; j++)
        {
            if (j >= (n + 1) - i)
            {
                printf("%3d   ", nCr(i - 1, r));
                r++;
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}
int nCr(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    else
        return (nCr(n - 1, r - 1) + nCr(n - 1, r));
}
