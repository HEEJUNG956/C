#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 미해결

int main()
{
    int t;
    int a, b;
    scanf("%d", &t);
    vector<pair<int, int>> answer;

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        answer.push_back({ b,a });
    }
    sort(answer.begin(), answer.end());

    for (int i = 0; i < t; i++)
    {
        printf("%d %d\n", answer[i].second, answer[i].first);
    }
}

