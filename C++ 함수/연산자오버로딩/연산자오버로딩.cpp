#include <iostream>
using namespace std;

//class A
//{
//public:
//    int n1;
//
//    A(int n1)
//    {
//        this->n1 = n1;
//    }
//};
//
//A operator+(const A& a1, const A& a2)
//{
//    A a(a1.n1 + a2.n1);
//    return a;
//}
//
//int main()
//{
//    A a1(10);
//    A a2(20);
//
//    A a3 = a1 + a2;
//    printf("%d\n", a3.n1);
//
//    return 0;
//}

// 연산자 오버라이딩
//class A
//{
//public:
//	int n1;
//	A(int n1)
//	{
//		this->n1 = n1;
//	}
//};
//
//A& operator++(A& a1)		// 전위증가
//{
//	a1.n1++;
//	return a1;
//}
//
//A operator++(A& a1, int)	// 후위증가
//{
//	A temp(a1.n1);
//	a1.n1++;
//	return temp;
//}
//
//int main(void)
//{
//	A a(10);
//
//	++a;
//	printf("%d\n", a.n1);
//
//	A p = a++;
//
//	printf("%d\n", p.n1);
//	printf("%d\n", a.n1);
//
//	return 0;
//}

class A
{
public:
	int n1;
	A(int n1)
	{
		this->n1 = n1;
	}
};

A operator+(const int num, const A& a)
{
	A temp(num + a.n1);
	return temp;
}

A operator+(const A& a, const int num)
{
	return num + a;
}

int main()
{
	A a(10);
	int num = 20;

	A p1 = num + a;
	A p2 = p1 + num;

	printf("%d\n", p1.n1);
	printf("%d\n", p2.n1);
}
