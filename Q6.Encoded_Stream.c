#include <stdio.h>
#include <string.h>
void bStream(int c)
{
    int j;
    for (j = 6; j + 1 > 0; j--)
    {
        if (c >= (1 << j))
        {
            c = c - (1 << j);
            printf("1");
        }
        else
            printf("0");
    }
}
int main()
{
    char a[100], b[100];
    int i, c;
    printf("Enter a string containing alphabets only :\n");
    gets(a);
    strcpy(b, a);
    strrev(b);
    if (strcmp(a, b) == 0)
    {
        printf("\nString is palindrome\n\n");
        printf("encodedStream = ");
        for (i = 0; a[i] != '\0'; i++)
        {
            c = a[i];
            bStream(c);
            if (a[i + 1] != '\0')
                printf("[1]");
        }
    }
    else
    {
        printf("\nString is not palindrome\n\n");
        printf("encodedStream = ");
        for (i = 0; a[i] != '\0'; i++)
        {
            c = a[i];
            bStream(c);
            if (a[i + 1] != '\0')
                printf("[0]");
        }
    }

    return 0;
}