#include <iostream> 
#include <string> 
#include <ctime>
#include <cstdlib> 
#include <Windows.h>
using namespace std; 


int main() 
{  
    srand((unsigned int)time(0));

    char word[5][7] = { "banana", "rocket", "yellow", "orange", "secret" };

    char* answer = word[rand() % 5];
    
    printf("%c\n", &answer);

    //char answer[5];
    char blind[] = "______";


    char c;
    int cnt, key, life = 10;

    while (1)
    {
        cnt = 0;
        key = 0;
        printf("%s : ", blind);
        scanf_s(" %c", &c);

        for (int i = 0; i < 6; i++)
        {
            if (c == blind[i])
            {
                key = 1;
                printf("이미 등록된 문자입니다 재입력해주세요. \n");
                break;
            }
            else if (c == answer[i])
            {
                blind[i] = c;
                cnt++;
            }
        }

        if (key == 1)
        {
            continue;
        }

        if (cnt == 0)
        {
            life--;
            if (life == 0)
            {
                printf("게임종료...\n");
                break;
            }
        }

        if (strcmp(blind, answer) == 0)
        {
            printf("%s\n", blind);
            printf("정답!!!");
            break;
        }
    }
}

