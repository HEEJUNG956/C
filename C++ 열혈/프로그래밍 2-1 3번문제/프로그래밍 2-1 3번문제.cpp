#include <iostream>
#pragma warning(disable:4996)
using namespace std;

void SwapPointer(int* (&ptr1), int* (&ptr2))
{
    int* pointer = ptr1;
    ptr1 = ptr2;
    ptr2 = pointer;
}
int main()
{
    int num1 = 5;
    int* ptr1 = &num1;
    int num2 = 10;
    int* ptr2 = &num2;
    printf("기존 포인터 ptr1이 가리키던 숫자 : %d\n", *ptr1);
    printf("기존 포인터 ptr2가 가리키던 숫자 : %d\n", *ptr2);
    SwapPointer(ptr1, ptr2);
    printf("바뀐 포인터 ptr1이 가리키던 숫자 : %d\n", *ptr1);
    printf("바뀐 포인터 ptr2가 가리키던 숫자 : %d\n", *ptr2);
}
