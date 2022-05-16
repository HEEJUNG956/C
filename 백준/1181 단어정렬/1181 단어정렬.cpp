#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 미해결

bool compare(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}
int main() 
{
	int n;
	vector<string> answer;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (find(answer.begin(), answer.end(), str) == answer.end())
			answer.push_back(str);
	}

	sort(answer.begin(), answer.end(), compare);

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
}