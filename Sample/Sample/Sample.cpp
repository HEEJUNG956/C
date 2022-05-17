#include <iostream>

int main()
{
    int n, temp;
    scanf("%d", &n);
    int cnt = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        for (int j = 1; j <= temp; j++)
        {
            if (temp % j == 0)
                cnt++;
        }
        if (cnt == 2)
            count++;
        cnt = 0;
    }
    printf("%d", count);
}
