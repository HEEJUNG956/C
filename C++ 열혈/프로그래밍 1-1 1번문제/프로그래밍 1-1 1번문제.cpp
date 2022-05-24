
#include <iostream>
using namespace std;
/*
사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성해 보자.
*/
int main()
{
    int temp;
    int answer = 0;
   
    printf("5개의 정수를 입력해서 그 합 구하는 프로그램 \n");
    for (int i = 1; i < 6; i++)
    {
        printf("%d 번째 수 : " , i);
        scanf_s("%d", &temp);
        answer += temp;
    }
    printf("최종 합계는 %d입니다.\n", answer);
}
