#include <iostream>
using namespace std;
int main()
{
    int n, result = 0;
    scanf("%d", &n);
    int temp, cnt = 0;
 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        for (int j = 1; j <= temp; j++)
        {
            if (temp % j == 0)
                cnt++;
        }
        if (cnt == 2)
            result++;
        cnt = 0;
    }

    printf("%d", result);
 }
