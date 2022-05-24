#include <iostream>
#pragma warning(disable:4996)
using namespace std;
/*

판매원들의 급여 계산 프로그램을 작성해보자.
이 회사는 모든 판매원에게 매달 50만원의 기본 급여와 물품 판매 가격의 12%에 해당하는 돈을 지급한다.
예를 들어서 민수라는 친구의 이번 달 물품 판매 금액이 100만원이라면, 50+100*0.12=62,
따라서 62만원을 급여로 지급 받는다

*/

int main()
{
    int work = 50; // 기본급여
    int money; // 이번달 판매 가격
    int result; // 급여

    while (1)
    {
        printf("이번달 판매 가격 입력 : ");
        scanf("%d", &money);

        result = 50 + money * 0.12;

        printf("이번달 총 급여는 %d 만원 입니다.\n", result);
    } 
}
