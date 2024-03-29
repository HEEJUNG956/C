﻿#include <iostream>
using namespace std;

int n, m;
int arr[9] = { 0 };
bool visited[9] = { 0 };

void dfs(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = num; i <= n; i++)
    {
        visited[i] = true;
        arr[cnt] = i;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    dfs(1, 0);
}
