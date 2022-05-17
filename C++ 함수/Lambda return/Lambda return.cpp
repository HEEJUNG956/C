#include <iostream>

using namespace std;

int main()
{
    double num = 10;
    // 리턴타입 int
    auto l1 = [](double a, int b) -> int
    {
        return a + b;
    };
    // 리턴타입 auto
    auto l2 = [](int a, int b) -> auto
    {
        a++;
        b--;

        return a + b;
    }(num, 5);
    // 리턴타입 int형
    int(*fc_1)() = []() -> int
    {
        return 100;
    };
    // 리턴타입 생략
    int(*fc_2)() = []()
    {
        return 10000;
    };

    // 반환값은 double로 반환되지만 return 타입이 int로 선언해서
    // 결과값은 정수 15로 출력
    printf("%d\n", l1(10.1, 5));
    printf("12\n");
    printf("%d\n", fc_1());
    printf("%d\n", fc_2());
}
