#include <iostream>
#include <mutex>
using namespace std;

//RAII Resource acquisition is initialization
// 자원 획득을 초기화한다.
bool error()
{
    return true;
}

void fnc()
{
    int* c = new int[100];
    unique_ptr<int> q(c);
    if (error()) return;
    delete[] c;

    mutex m;
    m.lock();
}
int main()
{
    fnc();
    printf("hi");
    _CrtDumpMemoryLeaks();
    return 0;
}
