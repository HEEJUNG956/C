#include <iostream>
#include <vector>
#include <algorithm>

// 미해결

using namespace std;
int main()
{
	int t, temp;
	scanf("%d", &t);
	vector<int> answer;

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &temp);
		answer.push_back(temp);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < t; i++)
	{
		printf("%d\n", answer[i]);
	}
}