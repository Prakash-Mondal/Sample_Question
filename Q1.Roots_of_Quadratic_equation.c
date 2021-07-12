#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, D, x1, x2;
    printf("Enter coefficient of x^2 , coefficient of x and constant term of quadratic equation : ");
    scanf("%f%f%f", &a, &b, &c);
    D = (b * b) - (4 * a * c);
    if (D == 0)
    {
        printf("\n Both roots are real and equal");
        x1 = -b / (2 * a);
        x2 = -b / (2 * a);
        printf("\n Roots of the quadratic quation are %f and %f", x1, x2);
    }
    else if (D > 0)
    {
        printf("\n Both roots real and distinct ");
        x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
        x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
        printf("\n Roots of the quadratic quation are %f and %f", x1, x2);
    }
    else
        printf("\n Both roots are imaginary");
    return 0;
}
