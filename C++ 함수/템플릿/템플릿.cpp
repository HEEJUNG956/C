#include <iostream>
#include <string.h>
using namespace std;

// 여러 객체 사용시 템플릿 사용
template <class T>
T Adder(T x, T y)
{
    return x + y;
}

template<>
const char* Adder(const char* arr1, const char* arr2)
{
    char* a = new char[100];
    strcpy(a, arr1);
    strcat(a, arr2);
    return a;
}
int main()
{
    printf("%s\n", Adder("hello ", "world"));
    printf("%d\n", Adder(10, 20));
    printf("%d\n", Adder(1.5, 20.999));
}
