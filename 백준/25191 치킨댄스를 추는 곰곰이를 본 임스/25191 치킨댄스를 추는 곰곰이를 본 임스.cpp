#include <iostream>
/*
    2022 - 05 - 16
    정희석
*/
int main()
{
    int n; // 치킨의 개수
    int a, b; // 콜라의 개수, 맥주의 개수
    int answer = 0;
    scanf("%d\n", &n);
    scanf("%d %d", &a, &b);
    int temp = n;
    for (int i = 0; i < temp; i++)
    {
        if (a - 2 >= 0 || b - 1 >= 0 &&  n >= 0)
        {
            if (a - 2 >= 0)
            {
                a = a - 2;
                n = n - 1;
                answer++;
            }
            else
            {
                b = b - 1;
                n = n - 1;
                answer++;
            }
        }

    }

    printf("%d\n", answer);
}

