#include <iostream>
using namespace std;

//  []          ()      ->type          {}
// 캡쳐블록  전달인자   -> 반환타입  함수몸통
// 함수객체와 함수포인터의 장점을 동시에 가지고있음
// 함수객체와는 다르게 class 선언 필요 없음
// 함수의 인라인화가 가능

class UP
{
public:
    bool operator()(int a, int b)
    {
        return (a > b ? true : false);
    }
};

class DOWN
{
public:
    bool operator()(int a, int b)
    {
        return (a < b ? true : false);
    }
};

template <class T>
void simple_sort(int *arr, int n, T cmp)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (cmp(arr[i], arr[j]))
                arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
        }
    }
}

void sort_print(int* arr, int n)
{
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[5] = { 10,5,41,100,2 };
    DOWN down;
    UP up;
    simple_sort(arr, 5, down);
    sort_print(arr, 5);
    simple_sort(arr, 5, up);
    sort_print(arr, 5);

    simple_sort(arr, 5, [](int a, int b)
        {
            return (a < b ? true : false);});
    sort_print(arr, 5);

    simple_sort(arr, 5, [](int a, int b)
        {
            return (a > b ? true : false);});
    sort_print(arr, 5);

    return 0;
}


