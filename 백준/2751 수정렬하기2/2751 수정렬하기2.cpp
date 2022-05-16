#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 미해결

int main()
{
	int n, temp;
	scanf("%d", &n);
	vector<int> answer;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		answer.push_back(temp);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", answer[i]);
	}
}

