#include <iostream>
#include <utility>
using namespace std;
int main()
{
    int t;
    int rank = 1;
    pair<int, int> arr[50];
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
                rank++;
        printf("%d ", rank);
        rank = 1;
    }
}
