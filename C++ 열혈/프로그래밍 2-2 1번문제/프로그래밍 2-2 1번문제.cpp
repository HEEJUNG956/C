#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int main()
{
    const int num = 12;
    const int* ptr = &num;
    const int* (&pointer) = ptr;
    printf("포인터 변수의 값 : %d\n", *ptr);
    printf("참조자의 값 : %d\n", *pointer);
    return 0;
}
