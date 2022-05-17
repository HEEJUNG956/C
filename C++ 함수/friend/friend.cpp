#include <iostream>
#include <string>
using namespace std;

class A
{
private:
    int num;
    string name;
    friend class B;
public:
    A(){}

    A(int num, string name)
    {
        this->num = num;
        this->name = name;
    }
};

class B 
{
    A* a;
public:
    void createA()
    {
        a = new A(10, "haha");
    }

    int sum()
    {
        return a->num + 10;
    }

    void fix_Name(string name)
    {
        a->name = name;
    }

    void showA()
    {
        cout << a->name << endl;
    }
};

// Class B가 A의 private변수에 접근해서 그 변수를 사용하고있음
// 정보은닉 위반방법으로 좋은 방법은 아님
int main()
{
    B b;
    b.createA();
    b.sum();
    b.fix_Name("choi");
    b.showA();

    return 0;
}