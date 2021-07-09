#include <stdio.h>
int main()
{
    int i, n;
    double Xi[100], fi[100], Xavg = 0, sum_of_fi = 0;
    printf("Enter how many numbers are in the list(n) : ");
    scanf("%d", &n);
    printf("Condition 1 : 0 <= fi <= 1         Condition 2 : f1 + f2 + ... + fn = 1\n");
    printf("Enter the values of Xi and their fractional weights fi one by one :\n");
    for (i = 1; i <= n; i++)
    {
        printf("Enter X%d : ", i);
        scanf("%lf", &Xi[i]);
        printf("Enter f%d : ", i);
        scanf("%lf", &fi[i]);
    }
    for (i = 1; i <= n; i++)
    {
        sum_of_fi = sum_of_fi + fi[i];
    }
    if (sum_of_fi == 1)
    {
        for (i = 1; i <= n; i++)
        {
            Xavg = Xavg + Xi[i] * fi[i];
        }
        printf("Xavg = %lf", Xavg);
    }
    else
        printf("Condition not satisfied.");
    return 0;
}
