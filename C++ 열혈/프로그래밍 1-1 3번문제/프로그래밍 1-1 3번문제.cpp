#include <iostream>
#pragma warning(disable:4996)
using namespace std;
//숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해보자.
int main()
{
    int temp;
    printf("몇 단을 구할 것이냐 ? => ");
    scanf("%d", &temp);
    printf("%d 단 나열\n", temp);
    for (int i = 1; i < 10; i++)
    {
        
        printf("%d X %d = %d\n", temp, i, temp * i);
    }
}
