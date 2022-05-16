#include <iostream>
#define max_int 1000001
#define lld long long
using namespace std;

// 미해결

int n, a[max_int], b, c;
lld result;
int main()
{
	scanf("%d", &n); // 시험장의 개수
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]); // 응시자의 수
	}
	scanf("%d %d", &b, &c); // 총감독의 감시 수와 부감독의 감시 수 입력
	for (int i = 1; i <= n; i++)
	{
		// 총 감독관의 수
		a[i] = a[i] - b;
		result++;

		// 부 감독관의 수
		if (a[i] > 0)
		{
			// 나눗셈을 통해서 부 감독관 수 계산
			result += a[i] / c;
			// 나머지가 있으면 부 감독관을 한명더 증가
			if (a[i] % c > 0) result++;
		}
	}
	printf("%lld\n", result);
}