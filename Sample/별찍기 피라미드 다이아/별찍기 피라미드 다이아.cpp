#include <iostream>
using namespace std;
int main()
{
    int temp;
    while (1)
    {
        printf("별찍기 연습 (피라미드, 다이아)\n");
        printf("찍을 개수 : ");
        scanf_s("%d", &temp);

        printf("직각삼각형\n");
        for (int i = 0; i < temp; i++)
        {
            for (int j = 0; j <= i; j++)
                printf("*");
            printf("\n");
        }
        printf("\n");

        printf("피라미드\n");
        for (int i = 1; i <= temp; i++)
        {
            for (int j = temp; j > i; j--)
                printf(" ");
            for (int j = 1; j <= 2 * i - 1; j++)
                printf("*");
            printf("\n");
        }
        printf("\n");

        printf("다이아몬드\n");
        for (int i = 1; i <= temp; i++)
        {
            for (int j = temp; j > i; j--)
                printf(" ");
            for (int j = 1; j <= 2 * i - 1; j++)
                printf("*");
            printf("\n");
        }
        for (int i = 1; i <= temp; i++)
        {
            for (int j = 0; j < i; j++)
            {
                printf(" ");
            }
            for (int j = 2 * temp - 1; j > 2 * i; j--)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    
}

