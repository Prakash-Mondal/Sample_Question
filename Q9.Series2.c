#include <stdio.h>
int main()
{
    double i, n, Sn = 0;
    printf("Enter the limit of the series n : ");
    scanf("%lf", &n);
    for (i = 1; i <= n; i++)
    {
        Sn = Sn + (1 / (4 * i - 1));
    }
    printf("\n Sn = %.10lf", Sn);
    return 0;
}
