#include <iostream>

// 미해결

int getNum(int a, int b)
{
	if (b == 1)
		return 1;
	if (a == 0)
		return b;
	return (getNum(a - 1, b) + getNum(a, b - 1));
}


int main()
{
	int t, k, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d\n%d", &k, &n);
		printf("%d\n", getNum(k, n));
	}
}
