#include <iostream>

int a, b, c; // 고정비용, 가변비용, 노트북가격
int main()
{
    scanf("%d %d %d", &a, &b, &c);
    int count = 1; // 노트북 대수
    if (b >= c)
    {
        printf("-1");
        return 0;
    }
    // 코드는 맞지만 시간초과로 인해 불가능 while문 못사용
    //else
    //{
    //    while (1)
    //    {
    //        // 고정비용 > 순이익 * 판매대수
    //        if (a > (c - b) * count)
    //            count++;
    //        else
    //            break;
    //    }
    //}
    printf("%d", a / (c - b) + 1);
}
