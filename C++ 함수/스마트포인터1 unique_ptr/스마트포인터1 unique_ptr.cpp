#include <iostream>
#include <memory>

using namespace std;
// unique_ptr 하나의 변수에 하나만 사용 가능
class A {
private:
    int* num;
public:
    A() : num(new int[100])
    {
        for (int i = 0; i < 100; i++)
            num[i] = i;
    }

    ~A()
    {
        printf("소멸자 호출!!\n");
        delete[] num;
    }

    int* return_ptr()
    {
        return num;
    }
};

int* fnc1()
{
    unique_ptr<A> u_ptr = make_unique<A>();
    int* p = u_ptr->return_ptr();

    printf("%d\n", p[10]);
    return u_ptr->return_ptr();
}

int main(void) {

    //unique_ptr<int[]> p1 = make_unique<int[]>(10);
    //p1[0] = 1; p1[1] = 2; p1[2] = 3;    //p1스마트포인터 배열 10개 선언

    //unique_ptr<int> p2 = make_unique<int>(5);   // unique_ptr<int>p2(new int(5));
    //int* num = new int(10);
    //unique_ptr<int> p3(move(num));

    //cout << p1[0] << endl;   //output : 1
    //cout << *p2 << endl;     //output : 5
    //cout << *p3.get() << endl;//output : 10
    //cout << *num << endl;     //output : 10

    //p3.reset();    //가르키고 있는 값 해제
    //cout << *num << endl;     //output: -572662307(쓰레기 값)

    //unique_ptr<A> a1 = make_unique<A>();
    ////unique_ptr<A> a2 = a1;  //error!!
    //unique_ptr<A> a2 = move(a1);    //OK!!

    int* p = fnc1();
    printf("%d\n", p[10]);
    return 0;
}