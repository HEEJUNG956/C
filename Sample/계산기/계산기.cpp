#include <iostream>
using namespace std;

int temp;
void menu();

int main()
{
    int q;
    printf("값을 입력해주세요 : ");
    cin >> q;

    printf("1. 더하기\n");
    printf("2. 빼기\n");
    printf("3. 곱하기\n");
    printf("4. 나누기\n");
    printf("원하시는 수식을 입력해주세요 : ");
    cin >> temp;

    menu();
}

void menu()
{
    switch (temp)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        printf("존재하지 않는 수식입니다.");
        break;
    }
}