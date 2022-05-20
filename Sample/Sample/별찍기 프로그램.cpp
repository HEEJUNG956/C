#include "basic.h"

int main() 
{
    int n;
    printf("과제명 : 별찍기 문제 \n");
    printf("라인수를 입력하세요 : ");
    cin >> n;

    printf("정사각형\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("*");
        printf("\n");
    }
    
    printf("직각삼각형\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
            printf("*");
        printf("\n");
    }

    printf("역직각삼각형\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            printf("*");
        printf("\n");
    }

    printf("이등변삼각형\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
            printf(" ");
        for (int j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }

}
