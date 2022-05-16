#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, temp;
    scanf("%d", &n);
    int count[10001] = { 0 }; // 0으로 초기화

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        count[temp]++;
    }

    for (int i = 0; i < 10001; i++)
        for (int j = 0; j < count[i]; j++)
            printf("%d\n", i);
    return 0;
}

