﻿#include <iostream>
#include <cmath>
using namespace std;

// 미해결

int main()
{
    int min, max;
    scanf("%d %d", &min, &max);
    bool* prime;
    prime = new bool[max + 1];
    fill_n(prime, max + 1, 1);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= sqrt(max); i++)
    {
        if (prime[i] == true)
            for (int j = i * 2; j <= max; j += i)
                prime[j] = false;
    }

    for (int i = min; i <= max; i++)
    {
        if (prime[i] == true)
            printf("%d\n", i);
    }
}