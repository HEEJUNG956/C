#include <iostream>
#include <string>
using namespace std;

// private로 선언된 생성자도 호출 가능
//class A 
//{
//private :
//    int num;
//public :
//    A(){}
//
//    A* createA(int number)
//    {
//        A* a = new A(number);
//        return a;
//    }
//
//    int get()
//    {
//        return num;
//    }
//private:
//    A(int num)
//    {
//        this->num = num;
//    }
//};

// A 출력후 B출력
//class B : public A
//{
//public:
//    B()
//    {
//        printf("Class B\n");
//    }
//};

// 생성자의 매개 변수, 인자값이 달라도 부모클래스 호출은 발생
//class B : public A
//{
//    int num;
//    string name;
//public:
//    B()
//    {
//        printf("Class B!!\n");
//    }
//    B(int num, string name)
//    {
//        this->num = num;
//        this->name = name;
//        printf("Class B!! num = %d, name = %s\n", this->num, this->name.c_str());
//    }
//};
class A {
private :
    int num;
public:
    A() 
    {
        cout << "Class A!!" << endl;
    }

    A(int num)
    {
        this->num = num;
        printf("Class A!!, num = %d\n", this->num);
    }

    int get()
    {
        return num;
    }
};

class B : public A 
{
    int num;
    string name;
public:
    B()
    {
        printf("Class B!!\n");
    }

    B(int num1, int num2, string name) : A(num1)
    {
        this->num = num2;
        this->name = name;
        printf("Class B!! num = %d, name = %s\n", this->num, this->name.c_str());
    }
};

int main()
{
    B b(100, 10, "jung");

    printf("Class A : num = %d\n", b.get());
    return 0;
}