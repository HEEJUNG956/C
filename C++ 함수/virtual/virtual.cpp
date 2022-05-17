#include <iostream>
using namespace std;

// virtual(가상함수)
// 자식클래스가 부모클래스의 함수를 가리는 형태가되어
// 자식클래스의 함수가 호출되게하는 것이 오버라이딩
// 즉 함수의 재정의

class A
{
private:
	int num = 100;
public:
	virtual void show_P()
	{
		printf("class A : %d\n", this->num);
	}

	void show_T()
	{
		printf("class A : %d\n", this->num);
	}

};

class B : public A
{
private:
	int num = 999999;
public:
	virtual void show_P()
	{
		printf("class B : %d\n", this->num);
	}
	void show_T()
	{
		printf("class B : %d\n", this->num);
	}
};

int main()
{
	A* a_1 = new A();
	A* a_2 = new B();

	a_1->show_P();
	a_1->show_T();

	printf("\n");
	printf("\n");

	// 가상함수로 선언된 멤버함수가 있고
	// 이를 오버라이딩한 자식클래스가 존재한다면
	// 형변환이 이루어진 포인터 변수는 
	// 자식클래스의 오버라이딩된 함수를 호출 할수 있는 기능생성
	a_2->show_P();
	a_2->show_T();
	return 0;
}
