#include <iostream>
using namespace std;

// 함수의 오버로딩을 할 시 반환값의 자료형은 동일하게하고
// 매기변수는 달라야 한다.
void fct_1(void)
{
    printf("나는 fuc_1()!!\n");
}
void fct_1(int num)
{
    printf("나는 fct_1(int num!!) : %d\n", num);
}
int fct_2(int num2)
{
    printf("나는 fct_2 int 형이다 : %d\n", num2);
    return num2;
}

int main()
{
    fct_1();
    fct_1(111);

    int num;
    num = fct_2(777);
    printf("num의 값 : %d\n", num);
    return 0;
}
