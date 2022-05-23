#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;
void staticTest()
{
    int local_count = 0;
    static int static_count = 0;
    local_count++;
    static_count++;

    printf("local_count : %d\n", local_count);
    printf("static_count : %d\n", static_count);
}

int main()
{
    cout << "staticTest함수 1번째호출 : \n";
    staticTest();
    cout << "staticTest함수 2번째호출 : \n";
    staticTest();
    cout << "staticTest함수 3번째호출 : \n";
    staticTest();
}