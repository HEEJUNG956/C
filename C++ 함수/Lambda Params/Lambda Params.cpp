#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    auto l1 = [](int a, int b)
    {
        a++;
        b--;
        return a + b;
    };

    // 소괄호() 안의 매개변수가 정해져있어서 결과값은 그대로
    auto l2 = [](int a, int b)
    {
        a++;
        b--;
        return a + b;
    }(num, 2);

    printf("%d\n", l1(10, 5));
    printf("%d", l2);
    return 0;
}
