#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i, n, position;
    double Xi[100], Xm = 0, sum = 0, diff[100], small, closest;
    printf("Enter how many numbers are in the list : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter X%d : ", i);
        scanf("%lf", &Xi[i]);
    }
    //Frist we will find the average.
    for (i = 1; i <= n; i++)
    {
        sum = sum + Xi[i];
    }
    Xm = sum / n;
    printf("Mean is = %lf\n", Xm);
    //Now we will find differences of each values form mean.
    printf("Absolute differences of Xi from mean Xm are :\n");
    for (i = 1; i <= n; i++)
    {
        diff[i] = fabs(Xm - Xi[i]);
        printf("%lf ", diff[i]);
    }
    printf("\n");
    //Now we will find the closest number from mean.
    small = diff[1];
    closest = Xi[1];
    position = 1;
    for (i = 2; i <= n; i++)
    {
        if (small > diff[i])
        {
            small = diff[i];
            closest = Xi[i];
            position = i;
        }
    }
    printf("The real number Xi to which the mean Xm is closest is %lf and the position of Xi is %d", closest, position);

    return 0;
}
