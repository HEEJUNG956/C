#include <iostream>
#include <vector>
using namespace std;



// 일반재귀함수
int Fibo(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return Fibo(n - 1) + Fibo(n - 2);
}

// 꼬리재귀함수
int FiboTailRec(int n, int before, int next)
{
    if (n == 0)
        return before;
    else
        return FiboTailRec(n - 1, next, before + next);
}


int FiboTail(int n)
{
    return FiboTailRec(n, 0, 1);
}

// for문을 이용한 반복문
int FiboLoop(int n)
{
    int before = 0, cur = 1, i, temp;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        for (i = 1; i < n; i++)
        {
            temp = cur;
            cur = before + cur;
            before = temp;
        }
        return cur;
    }
}

int main()
{
    int i, num;
    printf("피보나치 수열 문제\n");
    printf("피보나치 수 입력 : ");
    scanf_s("%d", &num);
     
    // 일반 재귀
    printf("일반 재귀\n");
    for (i = 1; i < num + 1; i++)
        printf("%d ", Fibo(i));
    printf("\n");

    // 꼬리 재귀
    printf("꼬리 재귀\n");
    for (i = 0; i < num; i++)
        printf("%d ", FiboTail(i));
    printf("\n");

    // for문을 이용한 반복문
    printf("for문\n");
    for (i = 0; i < num; i++)
        printf("%d ", FiboLoop(i));
    printf("\n");

    return 0;
}
