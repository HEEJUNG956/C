#include <iostream>


int main()
{
	int num = 10;
	int* p = &num;

	int sum = num + *p;
	printf("변수의 주소값 p : %d\n", p);
	printf("변수의 값 *p : %d\n", *p);
	printf("주소 값 &p : %d\n", &p);

	//p = p가 가르키고 있는 변수의 주소 값(num의 주소 값)
	//* p = p가 가르키고 있는 변수의 값(num의 값)
	//& p = p의 주소 값
	return 0;
}