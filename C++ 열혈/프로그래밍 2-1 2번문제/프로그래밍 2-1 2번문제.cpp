#include <iostream>
#pragma warning(disable:4996)
using namespace std;

void SwapByRef2(int& ref1, int& ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main()
{
    int val1 = 10;
    int val2 = 20;
    SwapByRef2(val1, val2);
    printf("val1 : %d\n", val1);
    printf("val2 : %d\n", val2);
    return 0;
}
