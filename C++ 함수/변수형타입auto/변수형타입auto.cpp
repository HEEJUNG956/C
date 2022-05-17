#include <iostream>
using namespace std;

// auto 자료형을 지정해주지 않아도 변수초기값에 따라 타입 결정
// 변수선언과 동시에 초기화
// 매기변수로는 사용 불가능
// return 값은 auto로 줘도 괜찮다

// 에러
//void add(auto a, auto b){}

auto cal(int n1, int n2)
{
    return n1 + n2;
}

int main()
{
    auto a1 = 10;
    auto a2 = 5.41;
    auto s = "hello";

    printf("%d\n", sizeof(a1));
    printf("%d\n", sizeof(a2));
    printf("%d\n", strlen(s));

    printf("%d\n", cal(70,7));

    // 에러
    /*auto a;
    a = 10; */
}


