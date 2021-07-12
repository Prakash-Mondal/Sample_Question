#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d;
    printf("Enter The values of a ,b, c and d of the Cubic equation :\n");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int x = 0, eq_value;
    printf("Integral roots of the Cubic equation (%d)*x^3 + (%d)*x^2 + (%d)*x + (%d) is :\n", a, b, c, d);
    while (1)
    {
        eq_value = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
        if (eq_value == 0)
            printf("%d\n", x);
        x--;
        if (eq_value < d && eq_value < (a + b + c + d) && eq_value < 0)
            break;
    }
    x = 1;

    while (1)
    {
        eq_value = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
        if (eq_value == 0)
            printf("%d\n", x);
        x++;
        if (eq_value > d && eq_value > (a + b + c + d) && eq_value > 0)
            break;
    }
}
