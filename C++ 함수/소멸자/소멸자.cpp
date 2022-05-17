#include <iostream>
using namespace std;

// 소멸자란 객체의 사용이 끝나고 메모리가 반환될때 실행되는 코드
// ~ 로 시작
class A
{
    int* num;
public:
    A()
    {
        num = new int[10];
    }

    ~A()
    {
        delete num;
    }
};
int main()
{
    A a;
    return 0;
}
