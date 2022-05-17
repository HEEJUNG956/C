#include <iostream>
#include <string>
using namespace std;

// 생성자 : 객체 선언시 자동으로 실행되는 코드(초기값 부여시 사용)

class A {
private:
    int num;
    string name;
public:
    A(int num, char* name)
    {
        this->num = num;
        this->name, name;
    }
};
int main()
{
    A a(10, "Jung");

    return 0;
}

