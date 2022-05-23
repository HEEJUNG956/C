#include <iostream>
#include <random>
#include <string>

using namespace std;
int main()
{
    srand((unsigned int)time(0));
    
    
    while (true)
    {
        int temp;
        printf("가위바위보 게임 시작!\n");
        string player;
        string computer;
        printf("무엇을 내시겠습니까?\n");
        printf("1. 바위\n");
        printf("2. 보\n");
        printf("3. 가위\n");
        scanf("%d", &temp);

        switch (temp)
        {
        case 1:
        {
            player = "바위";
            break;
        }
        case 2:
        {
            player = "보";
            break;
        }
        case 3:
        {
            player = "가위";
            break;
        }
        };

        if (temp < 1 || temp > 3)
        {
            printf("잘못입력했습니다.\n");
            system("pause");
            system("cls");
            continue;
        }
        
        
        printf("플레이어는 %s를 냈습니다.\n", player.c_str());
        
        int temp_c = rand() % 3;
        switch (temp_c)
        {
            case 1:
            {
                computer = "가위";
                break;
            }
            case 2:
            {
                computer = "바위";
                break;
            }
            case 3:
            {
                computer = "보";
                break;
            }
        }

        if (temp_c < 1 || temp_c > 3)
        {
            printf("잘못입력했습니다.\n");
            system("pause");
            system("cls");
            continue;
        }
        
        printf("컴퓨터는 %s를 냈습니다.\n", computer.c_str());
        if (player == "가위")
        {
            if (computer == "가위")
                printf("비겼습니다.\n");
            else if (computer == "바위")
                printf("졌습니다.\n");
            else if (computer == "보")
                printf("이겼습니다.\n");
        }
        else if (player == "바위")
        {
            if (computer == "가위")
                printf("이겼습니다.\n");
            else if (computer == "바위")
                printf("비겼습니다.\n");
            else if (computer == "보")
                printf("졌습니다.\n");
        }
        else if (player == "보")
        {
            if (computer == "가위")
                printf("졌습니다.\n");
            else if (computer == "바위")
                printf("이겼습니다\n");
            else if (computer == "보")
                printf("비겼습니다.\n");
        } 
        
    }
    
}

