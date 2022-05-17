#include <iostream>
using namespace std;

// 모든 주소의 값이 동일하다.
// this는 자기자신을 가리키는 키워드로 멤버변수 초기화시 사용
//class A
//{
//    int num;
//public:
//    void print_This()
//    {
//        printf("Class A의 this 주소 : %d\n", this);
//    }
//
//    A* return_A()
//    {
//        return this;
//    }
//};
//
//int main()
//{
//    A a;
//    printf("a의 주소값 : %d\n", &a);
//    a.print_This();
//    printf("a.return_A()의 값 : %d\n", a.return_A());
//}

 

// *p가 가르키는 값을 참조
// int &ref1 = *p / int &ref1 = num _1
//class A {
//	int num;
//public:
//	A(int num)
//	{
//		this->num = num;
//	}
//
//	int get_Num()
//	{
//		return num;
//	}
//};
//
//int main(void)
//{
//	A a(10);
//	printf("%d\n", a.get_Num());
//
//	int num_1 = 111;
//	int* p = &num_1;
//	
//	int& ref1 = *p;
//	int* (&ref2) = p;
//
//	printf("%d\n", *p);
//	printf("%d\n", &ref1);  //ref1의 주소 값(참조자)
//	printf("%d\n", ref2);   //ref2가 가르키는 주소 값(참조 포인터)
//	printf("%d\n", p);      //p가 가르키는 주소 값
//	printf("%d\n", &num_1); //num_1의 주소 값
//	printf("%d\n", &ref2);  //ref2의 주소 값
//
//	return 0;
//}


class A 
{
public:
	int num = 10;
	
	void print_This()
	{
		cout << this << "\n";
	}

	A& return_This()
	{
		return *this;
	}
};

int main()
{
	A a;
	a.print_This();
	A& ref = a.return_This();

	ref.print_This();

	printf("a의 주소값 %d\n", &a);
	printf("ref의 주소값 %d\n", &ref);

	return 0;
}