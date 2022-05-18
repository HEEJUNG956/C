#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_fnc(int n)
{
    printf("%d ", n);
}

int main()
{
    int arr[10]{ 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v = { 5,2,3,4,5 };
    vector<int>::iterator itr = v.begin();

    printf("배열 호출 : ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("벡터 호출 : ");
    for (int i = 0; i < 5; i++)
        printf("%d ", v.at(i));
    printf("\n");

    printf("iterator 호출 : ");
    for (itr; itr != v.end(); itr++)
        printf("%d ", *itr);
    printf("\n");

    printf("함수 호출 : ");
    for (int i = 0; i < 10; i++)
        print_fnc(arr[i]);

    printf("\nforeach\n");
    auto pr = for_each(v.begin(), v.end(), print_fnc);


    printf("arr[9]의 값 : %d\n", arr[9]);
    for_each(arr, &arr[9], print_fnc);
    printf("\n");

    printf("arr[10]의 값 : %d\n", arr[10]);
    for_each(arr, &arr[10], print_fnc);
    printf("\n");

    printf("for_each문 함수 호출 : ");
    for_each(v.begin(), v.end(), print_fnc);
    printf("\n");

    /*printf("for_each문 Lambda 호출 : ");
    for_each(itr, itr + v.size(), [](auto& n) {
        cout << n << " ";
        });*/
    return 0;
}
