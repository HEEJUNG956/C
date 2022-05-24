#include <iostream>
#pragma warning (disable:4996)
using namespace std;

void add(int& ptr)
{
    ptr += 1;
}

void reverse(int& ptr)
{
    ptr *= -1;
}
int main()
{
    int num;
    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);
    printf("원래 숫자 : %d\n", num);
    add(num);
    printf("1 증가시킨 숫자 : %d\n", num);
    reverse(num);
    printf("부호 바꾼 숫자 : %d\n", num);
    return 0;
}