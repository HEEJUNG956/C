#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)
/*
프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서, 입력 받은 데이터를 그대로 출력하는 프로그램을 작성해보자
*/

int main()
{
    char name[10];
    char phone[100];

    printf("이름 입력 : ");
    scanf("%s", &name);
    printf("전화번호 입력 : ");
    scanf("%s", &phone);

    printf("입력한 이름 %s \n", name);
    printf("입력한 전화번호 %s \n", phone);
}

