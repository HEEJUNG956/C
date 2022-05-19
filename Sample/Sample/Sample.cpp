#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    char temp;

    if (a && b == 1)
        printf("참\n");
    else
        printf("거짓\n");

    if (a || b == 1)
        printf("참\n");
    else
        printf("거짓\n");

    if (!a == 1)
        printf("참\n");
    else
        printf("거짓\n");

    return 0;
}