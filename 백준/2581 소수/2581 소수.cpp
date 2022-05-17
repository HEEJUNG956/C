#include <iostream>

int main()
{
    int m, n;
    int max = 0, min = -1, cnt = 0;
    int count = 0;
    scanf("%d\n%d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                cnt++;
        }
        if (cnt == 2)
        {
            if (min == -1)
            {
                min = i;
            } 
            max += i;
            count++;
        }
        cnt = 0;
    }

    if (count == 0)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n%d", max, min);
    return 0;
}

