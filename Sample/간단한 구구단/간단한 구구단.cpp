#include <iostream>

int main()
{
    int temp;
    while (1)
    {
        printf("구 구 단 만 들 기!\n");
        printf("몇 단을 구할까? : ");
        scanf_s("%d", &temp);

        for (int i = 1; i <= 9; i++)
            printf("%d X %d = %d\n", temp, i, temp * i);
        system("pause");
        system("cls");
    }
}
