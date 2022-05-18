#include <iostream>
using namespace std;
class Plus
{
public:
	Plus()
	{
		num = 0;
	}
	int operator()()
	{
		num++;
		return num;
	}
	friend ostream& operator<<(ostream&, const Plus&);

private:
	int num;
};
class Minus
{
public:
	Minus()
	{
		num = 0;
	}
	int operator()()
	{
		num--;
		return num;
	}
	friend ostream& operator<<(ostream&, const Minus&);

private:
	int num;
};

ostream& operator<<(ostream& os, const Plus& plus)
{
	os << plus.num << endl;
	return os;
}

ostream& operator<<(ostream& os, const Minus& minus)
{
	os << minus.num << endl;
	return os;
}

template<class T>
T choice(T op)
{
	return op;
}

int main()
{
	Plus plus;
	Minus minus;
	printf("%d\n", choice(plus()));
	printf("%d\n", choice(minus()));
	return 0;
}