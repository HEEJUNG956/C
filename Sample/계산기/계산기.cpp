#include <iostream>
using namespace std;

int temp, a, b;
char c;
void menu();

int main()
{
    for (;;)
    {
        printf("계산기 시작 : ");
        cin >> c;
        
        if (c == 'y' || c == 'Y')
        {
            printf("값을 입력해주세요 : ");
            cin >> a;

            printf("1. 더하기\n");
            printf("2. 빼기\n");
            printf("3. 곱하기\n");
            printf("4. 나누기\n");
            printf("원하시는 수식을 입력해주세요 : ");
            cin >> temp;

            menu();
        }
        else if (c == 'n' || c == 'N')
        {
            printf("종료합니다. \n");
            break;
        }
        else
        {
            printf("잘못입력하셨습니다. \n");
        }
            
       }

}

void menu()
{
    switch (temp)
    {
    case 1:
        printf("더할 값을 입력해주세요 : ");
        cin >> b;
        printf("%d + %d = %d\n", a, b, a + b);
        break;
    case 2:
        printf("뺄 값을 입력해주세요 : ");
        cin >> b;
        printf("%d - %d = %d\n", a, b, a - b);
        break;
    case 3:
        printf("곱할 값을 입력해주세요 : ");
        cin >> b;
        printf("%d * %d = %d\n", a, b, a * b);
        break;
    case 4:
        printf("나눌 값을 입력해주세요 : ");
        cin >> b;
        printf("%d / %d = %d\n", a, b, a / b);
        break;
    default:
        printf("잘못 입력하셨습니다. \n");
    }
}