#include <iostream>
using namespace std;

typedef bool(*Cmp)(int, int);
bool Up(int x, int y) { return (x > y ? true : false); }
bool Down(int x, int y) { return (x < y ? true : false); }

void simple_sort(int* arr, int n, Cmp cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (cmp(arr[i], arr[j]))
			{
				arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
			}
		}
	}
}

void sort_print(int* arr, int n)
{
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int arr[5] = { 10, 5, 41, 100, 2 };

	simple_sort(arr, 5, Down);
	sort_print(arr, 5);

	simple_sort(arr, 5, Up);
	sort_print(arr, 5);

	return 0;
}