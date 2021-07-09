#include <stdio.h>
int Ackerman(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return Ackerman(m - 1, 1);
    else if (m > 0 && n > 0)
        return Ackerman(m - 1, Ackerman(m, n - 1));
}
int main()
{
    int m, n;
    printf("Enter the values of m ( 0<=m <= 3) and n (0 <= n <= 4) :\n");
    scanf("%d%d", &m, &n);
    printf("A(m,n) = %d", Ackerman(m, n));
    return 0;
}
