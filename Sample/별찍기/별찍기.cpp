#include <iostream>
using namespace std;
int main()
{
    int temp;
    printf("별찍기 문제\n");
    printf("라인수를 입력하세요 : ");
    scanf_s("%d", &temp);

    printf("정사각형\n");
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp; j++)
            printf("*");
        printf("\n");
    }

    printf("\n직각삼각형\n");
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("*");
        printf("\n");
    }


    printf("\n역직각삼각형\n");
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int j = temp; j > i; j--)
            printf("*");
        printf("\n");
    }


    printf("\n이등변삼각형\n");
    for (int i = 1; i <= temp; i++)
    {
        for (int j = temp; j > i ; j--)
        {
            printf(" ");
        }
        for (int j = 1; j < 2 * i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
