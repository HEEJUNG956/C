#include <iostream>
using namespace std;

// 복사생성자 = 클래스이름(const 클래스이름 &참조변수)
// 상수로 선언된 참조자이며 type은 자기자신이 되는 것
// 기존값을 복사해 전달해주는 개념
// 대입연산 할때, 매개변수로 들어갈때, 반환값이 있을때 호출

class A
{
    int num;
    string name;
public:
    A(){}
    A(int num, string name)
    {
        this -> num = 10;
        this -> name = name;
    }

    A(const A& ref)
    {
        num = ref.num;
        name = ref.name;
        printf("복사생성자호출\n");
    }

    void fct_1(A obj)
    {
        printf("fct_1 함수실행\n");
    }

    A fct_2(void)
    {
        A obj;
        printf("fct_2 함수실행\n");
        return obj;
    }
};
int main()
{
    A a(10, "jung");
    a.fct_1(a);
    printf("fct_1 함수 실행 끝\n");
    A b = a.fct_2();
    printf("fct_2 함수 실행 끝\n");
}
