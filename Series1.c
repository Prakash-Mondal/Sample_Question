#include <stdio.h>
#include <math.h>
long unsigned int factorial(long unsigned int);
int main()
{
    long unsigned int i, n;
    double result = 0;
    printf("Enter the limit n : ");
    scanf("%lu", &n);
    for (i = 1; i <= (n - 2) / 2; i++)
    {
        result = result + (pow(-1, (1 + i))) / factorial(2 + 2 * i);
    }
    printf("%.16lf", result);
    return 0;
}
long unsigned int factorial(long unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
        return n * factorial(n - 1);
}