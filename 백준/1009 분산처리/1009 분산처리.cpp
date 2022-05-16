#include <iostream>
#include <math.h>
using namespace std;

int n;
int a, b;
int result = 0;

void input()
{
    scanf("%d %d", &a, &b);
}

int solution()
{
    if (b % 4 == 0)
        b = 4;
    else
        b %= 4;
    if (a % 10 == 0)
    {
        result = 10;
        return result;
    }
    else
    {
        a %= 10;
        result = pow(a, b);
        return result % 10;
    }
        
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        input();
        printf("%d\n", solution());
    }
    return 0; 
}

