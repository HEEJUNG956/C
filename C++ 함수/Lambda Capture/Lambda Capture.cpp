#include <iostream>
using namespace std;

// [capture](params) -> return
// 함수 몸통 뒤에 소괄호()를 있느냐에 따라 매커니즘이 달라진다.
// 람다에서 선언된 변수는 프로그램 끝날때까지 사라지지않는다.
// 외부변수와 같은이름으로 초기화를 한다면
// 해당 외부변수는 사용되지 않는다.
// capture블록에서 초기화된 변수는 const로 선언되어 변경불가능
//int main()
//{
//    int x = 10;
//    double y = 5.4;
//    string s = "jung";
//
//    auto l1 = [=]()
//    {
//        int cp_x = x;
//        double cp_y = y;
//        string cp_s = s;
//        return x + y;
//    }();
//
//    auto l2 = [=, x = x + 1]()
//    {
//        printf("l2함수의 x의 주소 값 : %x", &x);
//        return x * x;
//    };
//
//    printf("l1 = %f\n", l1);
//
//    printf("\nl2 = %d\n", l2());
//    printf("\nl2 = %d\n", l2());
//
//    printf("x = %d\n", x);
//    printf("main함수의 x 주소값 = %d\n", &x);
//}


int main()
{
	int x = 10;
	auto l1 = [&]()
	{
		x = 5;
		return x;
	};

	// l2 호출시 초기값이 미리 정의되어서 
	// x = 5가 아닌 10으로 가져옴
	auto l2 = [&, x = x + 100]()
	{
		return x;
	};

	printf("%d\n", l1());
	printf("main x : %d\n", x);
	printf("%d\n", l2());
	printf("main x : %d\n", x);
}