#include <iostream>
using namespace std;

//public = 어디서든 접근이 가능.
//protected = 상속관계일 때 접근이 가능
//private = 해당 클래스에서만 접근이 가능

class A
{
public:
    int num1;
    
    A() : num1(5), num2(6), num3(7){}

protected:
    int num2;
private:
    int num3;
};

// 상속관계
class B : public A 
// class B : protected B 라고 칭하면 
// 모든 접근 범위를 protected로 변경하겠다는 뜻
{
public:
    void setNum()
    {
        num1 = 10;      // 정상작동
        num2 = 100;     // 정상작동
        //num3 = 1000;  // 컴파일 에러
    }
};

int main()
{
    A a;

    printf("num1 : %d\n", a.num1); // 정상작동
    //printf("num2 : %d\n", a.num2); // 컴파일 에러
    //printf("num3 : %d\n", a.num3); // 컴파일 에러
}
