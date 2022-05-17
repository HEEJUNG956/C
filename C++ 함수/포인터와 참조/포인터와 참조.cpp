#include <iostream>

//포인터*
//= > 메모리의 주소를 가지고 있는 변수
//= > 주소 값을 통해 메모리 접근
//= > NULL 초기화 가능
//
//참조 &
//= > 자신이 참조하는 변수를 대신 할 수 있는 또하나의 이름
//= > NULL 초기화 불가능(선언과 동시에 초기화)

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