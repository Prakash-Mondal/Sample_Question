#include <stdio.h>
#include <string.h>
#define a "riot"
#define b "kill"
#define c "murder"
#define d "bomb"
#define e "attack"
#define f "shoot"
#define g "raging"

int main()
{
    char arr[100];
    printf("Enter a sentence :\n");
    gets(arr);
    if (strstr(arr, a) || strstr(arr, b) || strstr(arr, c) || strstr(arr, d) || strstr(arr, e) || strstr(arr, f) || strstr(arr, g))
        printf("\nViolence detected.\n");
    else
        printf("\nViolence not detected.\n");
    return 0;
}