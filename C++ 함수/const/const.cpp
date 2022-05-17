#include <iostream>
#include <string>
using namespace std;

//class A
//{
//private:
//    int num;
//    string name;
//public:
//    A(){}
//
//    A(int num, string name)
//    {
//        this->num = num;
//        this->name = name;
//    }
//
//    void show_Print() const 
//    {
//        printf("hi");
//        //num = 10; 컴파일 에러 const로 되어있어 변경불가능
//    }
//};
//
//int main()
//{
//    A a;
//    a.show_Print();
//    return 0;
//}

class A
{
private:
	const int n1 = 10;
	const int n2;

public:
	A(int _n2) : n2(_n2){}

	int sum() const
	{
		return n1 + n2;
	}

	const int sum(int num1, int num2)
	{
		return num1 + num2;
	}
};

// const가 붙으면 오버로딩이 가능
int main(void)
{
	A a(100);
	printf("%d\n", a.sum());

	const int num = a.sum(10, 20);
	printf("%d\n", num);

	return 0;
}
