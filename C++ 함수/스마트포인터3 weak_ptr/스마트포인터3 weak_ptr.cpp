#include <iostream>
#include <memory>
using namespace std;
// weak_ptr
class A
{
private:
	int* num;
public:
	A() : num(new int[100]){}

	~A()
	{
		printf("소멸자~\n");
		delete[] num;
	}
	void print_ptr() { printf("%x\n", num); }
};

void fnc(weak_ptr<A> wp)
{
	if (shared_ptr<A> temp = wp.lock())
	{
		printf("공유 포인터 있어요\n");
		temp->print_ptr();
		printf("(함수 안)공유 된 갯수 : %d\n", wp.use_count());
	}
	else
	{
		printf("공유 포인터 없어요\n");
	}
	printf("공유된 갯수 : \n", wp.use_count());
}

int main()
{
	shared_ptr<A> sh_p1 = make_shared<A>();
	shared_ptr<A> sh_p2 = sh_p1;
	weak_ptr<A> wp1 = sh_p1;

	fnc(wp1);
	return 0;
}

