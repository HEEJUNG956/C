#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 미해결

int main()
{
    int t;
    scanf("%d", &t);
    int x, y;
    vector<pair<int, int>> answer;

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &x, &y);
        answer.push_back({ x,y });
    }
    sort(answer.begin(), answer.end());

    for (int i = 0; i < t; i++)
    {
        printf("%d %d\n", answer[i].first, answer[i].second);
    }
}

