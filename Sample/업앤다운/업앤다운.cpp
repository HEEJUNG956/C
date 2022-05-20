#include <iostream>
#include <random>
#include<Windows.h>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    int min = 0, max = 100;
    int answer = (rand() % 100);
    int count = 0;
    int temp;

    for(;;)
    {
        printf("%d\n", answer);
        printf("과제명 : 업앤다운\n");
        printf("MIN : %d MAX : %d\n", min, max);
        printf("시도 횟수 : %d\n", count);
        printf("범위내 숫자를 입력하세요.\n");
        cin >> temp;
        if (answer > temp)
        {
            if (temp < min)
            {
                printf("min 값보다 작은 값입니다. ");
                printf("다시 입력해주세요\n");
                system("PAUSE");
            }
            else
            {
                printf("업\n");
                min = temp;
                count++;
                system("PAUSE");
            }
        }
        else if (answer < temp)
        {
            if (temp > max)
            {
                printf("max 값보다 큰 값입니다. ");
                printf("다시 입력해주세요\n");
                system("PAUSE");
            }
            else
            {
                printf("다운\n");
                max = temp;
                count++;
                system("PAUSE");
            }
        }
        else if (temp == answer)
        {
            printf("정답입니다!\n");
            printf("시도 횟수 : %d\n", count);
            break;
        }
        system("cls");
    }
}

