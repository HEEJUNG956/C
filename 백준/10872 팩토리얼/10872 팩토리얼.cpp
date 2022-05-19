#include <iostream>
using namespace std;
int main()
{
    int t;
    int answer = 1;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        answer *= i;
    }
    printf("%d", answer);
}

