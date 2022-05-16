#include <iostream>
#include <cmath>
#include <cstdio>
#define lld long long
using namespace std;

    // 미해결

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        // 출발지점, 도착지점
        lld x, y;
        lld move, max = 0;
        scanf("%ld %ld", &x, &y);
        while (max * max <= y - x)
            max++;
        max--;
        move = 2 * max - 1;
        lld rem = y - x - max * max;
        rem = (lld)ceil((double)rem / (double)max);
        move += rem;
        printf("%lld\n", move);
    }
}

