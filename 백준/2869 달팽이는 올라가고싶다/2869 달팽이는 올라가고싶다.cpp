#include <iostream>

// 미해결

int main()
{
	int v, a, b; // 나무막대높이, 낮올라감, 밤내려감
	scanf("%d %d %d", &a, &b, &v);
	int answer;

	answer = (v - b - 1) / (a - b) + 1;
	printf("%d", answer);
}