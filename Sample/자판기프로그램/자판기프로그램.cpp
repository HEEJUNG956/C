#include <iostream>
#include <string>
using namespace std;
int main()
{
    while (1)
    {
        int coin = 0;
        int temp;
        string select = " ";
        printf("자판기에서 음료 뽑기\n");
        printf("자판기 메뉴 선택\n");
        printf(" 1.음료 \n 2.커피 \n 3.에너지드링크 \n");
        printf("선택해주세요 : ");
        scanf_s("%d", &temp);
        switch (temp)
        {
        case 1:
        {
            printf("음료 선택\n");
            system("cls");
            break;
        }
        case 2:
        {
            printf("커피 선택\n");
            system("cls");
            break;
        }
        case 3:
        {
            printf("에너지드링크 선택\n");
            system("cls");
            break;
        }
        default:
        {
            printf("1 ~ 3번을 입력해주세요\n");
            system("pause");
            system("cls");
            break;
        }
        }

        if (temp == 1)
        {
            int drink;
            printf("마실 음료를 선택해주세요\n");
            printf(" 1. 오렌지주스 \n 2. 포도주스 \n 3. 망고주스 \n");
            printf("선택해주세요 : ");
            scanf_s("%d", &drink);
            switch (drink)
            {
            case 1:
            {
                printf("오렌지주스를 선택했습니다.\n");
                printf("1000원입니다.\n");
                coin = 1000;
                select = "오렌지주스";
                system("cls");
                break;
            }
            case 2:
            {
                printf("포도주스를 선택했습니다.\n");
                printf("3000원입니다.\n");
                coin = 3000;
                select = "포도주스";
                system("cls");
                break;
            }
            case 3:
            {
                printf("망고주스를 선택했습니다.\n");
                printf("2000원입니다.\n");
                coin = 2000;
                select = "망고주스";
                system("cls");
                break;
            }
            default:
            {
                printf("1 ~ 3번을 입력해주세요\n");
                system("pause");
                system("cls");
                break;
            }
            }
        }

        else if (temp == 2)
        {
            int coffee;
            printf("마실 커피를 선택해주세요\n");
            printf(" 1. 아메리카노 \n 2. 카페라떼 \n 3. 밀크커피 \n");
            printf("선택해주세요 : ");
            scanf_s("%d", &coffee);
            switch (coffee)
            {
            case 1:
            {
                printf("아메리카노를 선택했습니다.\n");
                printf("1500원입니다.\n");
                coin = 1500;
                select = "아메키라노";
                system("cls");
                break;
            }
            case 2:
            {
                printf("카페라떼를 선택했습니다.\n");
                printf("2500원입니다.\n");
                coin = 2500;
                select = "카페라떼";
                system("cls");
                break;
            }
            case 3:
            {
                printf("밀크커피를 선택했습니다.\n");
                printf("500원입니다.\n");
                coin = 500;
                select = "밀크커피";
                system("cls");
                break;
            }
            default:
            {
                printf("1 ~ 3번을 입력해주세요\n");
                system("pause");
                system("cls");
                break;
            }
            }
        }
        else if (temp == 3)
        {
            int power;
            printf("마실 에너지드링크를 선택해주세요\n");
            printf(" 1. 파워에이드 \n 2. 게토레이 \n 3. 핫식스 \n");
            printf("선택해주세요 : ");
            scanf_s("%d", &power);
            switch (power)
            {
            case 1:
            {
                printf("파워에이드를 선택했습니다.\n");
                printf("1000원입니다.\n");
                coin = 1000;
                select = "파워에이드";
                system("cls");
                break;
            }
            case 2:
            {
                printf("게토레이를 선택했습니다.\n");
                printf("3000원입니다.\n");
                coin = 3000;
                select = "게토레이";
                system("cls");
                break;
            }
            case 3:
            {
                printf("핫식스를 선택했습니다.\n");
                printf("2000원입니다.\n");
                coin = 2000;
                select = "핫식스";
                system("cls");
                break;
            }
            default:
            {
                printf("1 ~ 3번을 입력해주세요\n");
                system("pause");
                system("cls");
                break;
            }
            }
        }

        if (coin == 0 && select == " ")
        {
            printf("선택한 메뉴가 없습니다 \n");
        }
        else
        {
            printf("선택하신 음료는 %s이고 가격은 %d입니다.\n", select.c_str(), coin);
        }
       
        int money;
        
            while (1)
            {
                if (coin == 0)
                    break;
                printf("돈을 넣어주시길 바랍니다.\n");
                printf("투입한 돈 입력 : ");
                scanf_s("%d", &money);
                if (money > coin)
                {
                    printf("거스름돈 %d를 받아가시면됩니다 감사합니다.\n", money - coin);
                    system("pause");
                    system("cls");
                    break;
                }
                else if (money == coin)
                {
                    printf("감사합니다.\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else if (money < coin)
                {
                    printf("투입하신 돈이 부족합니다.\n");
                    system("cls");
                }
            }
        system("pause");
        system("cls");
    }
}