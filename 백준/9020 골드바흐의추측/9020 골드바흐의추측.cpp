#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int max = 0;
	int t;
	scanf("%d", &t);
	int* even = new int[t];

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &even[i]);
		if (even[i] > max)
			max = even[i];
	}

	bool* prime = new bool[max + 1];
	fill_n(prime, max + 1, 1);
	prime[0] = false, prime[1] = false;
	for (int i = 2; i <= sqrt(max); i++)
		if (prime[i] == true)
			for (int j = i * 2; j <= max; j += i)
				prime[j] = false;

	for (int t1 = 0; t1 < t; t1++)
	{
		for (int j = even[t1] / 2; j > 0; j--)
		{
			if (prime[j] && prime[even[t1] - j])
			{
				printf("%d %d\n", j, even[t1] - j);
			}
		}
	}
}


// 8 2 3 5 7