#include <iostream>
using namespace std;

// 오버로딩과 다르게 함수의 반환값, 매개변수, 이름 모두 동일
// virtual기능 사용시 많은 도움

// A의 자식클래스인 B는 class A의 모든 함수와 멤버 변수를 사용가능
// B에서 A의 함수가 맘에 안들면 새로 함수를 같은이름으로 
// 정의하는 것을 오버라이딩이라고 부릅니다.
class A 
{
    int num = 10;
public :
    void show_Pt() 
    {
        printf("class A의 num : %d\n", num);
    }
};

class B : public A
{
    int num = 999;
public:
    void show_Pt()
    {
        printf("class B의 num : %d\n", num);
    }
};
int main()
{
    A a;
    B b;
    a.show_Pt();
    b.show_Pt();
}
