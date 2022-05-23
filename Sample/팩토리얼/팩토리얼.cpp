#include <iostream>
using namespace std;

// for문을 이용한
int fact(int num)
{
    int answer = 1;
    for (int i = 1; i <= num; i++)
    {
        answer *= i;
    }

    return answer;
}

// 재귀함수를 이용한
int fact1(int num)
{
    if (num <= 1) return 1;
    return num * fact1(num - 1);
}

// while문을 이용한
int fact2(int num)
{
    while (num != 1)
    {
        return num * fact2(num - 1);
    }

}
int main()
{
    int temp;
    printf("팩토리얼 문제\n");
    printf("팩토리얼을 실행할 숫자 : ");
    scanf("%d", &temp);

    printf("정답 : %d\n", fact2(temp));

}

