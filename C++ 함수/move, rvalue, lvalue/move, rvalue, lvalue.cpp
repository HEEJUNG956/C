#include <iostream>
#include <string>
#include <vector>
using namespace std;
// move()는 실제로 값을 이동시켜주는 게아니라
// rvalue로 바꿔주는 역할
// ravlue로 바뀐 후 데이터에 값이 입력되는 순간
// 사용자가 정의한 move생성자에 의해 데이터는 복사가 아닌 이동
class Sample
{
    // rvalue는 실체가 없는 값
    // 참조자 &ref로 받을 수 없는 모든 데이터
    // lvalue는 주소 값을 받을 수 있는 모든 것
    int i = 1;      // rvalue
    int t = i;      // lvalue
    int z = i + t;  // rvalue

    //int& a1 = 1;    // error
    //int& a2 = i;    // ok
    //int& a3 = i + t;// error

    // move()함수
    //string s_1 = "jung";
    //string s_2 = move(s_1);
    //int i = 5;
    //int j = move(i);
};

class A 
{
private:
    string s;
    char* data;

public:
    A(){}

    A(string s) : s(s), data(new char[10000])
    {
        printf(" constructor\n");
    }
    
    A(const A& ref)     // 복사생성자
    {
        this->s = ref.s;
        this->data = new char[10000];
        printf(" copy constructor\n");
    }

    A(A&& ref)          // 이동생성자
    {
        this->s = ref.s;
        this->data = ref.data;
        ref.data = nullptr;
        printf(" move constructor\n");
    }
    ~A()
    {
        delete[]data;
        printf(" ~constructor\n");
    }

    void print()
    {
        printf("data가 가르키고 있는 주소 값 : %x\n", data);
    }
};

int main()
{
    vector<A> v;
    A a("a");
    A b("b");

    printf("///////////////////복사생성자//////////////////\n");
    v.push_back(a);
    v[0].print();
    printf("벡터가 가리키고 있는 주소 값 : %d\n", &v[0]);
    printf("v.capacity() : %d\n", v.capacity());

    v.push_back(b);
    v[0].print();
    printf("벡터가 가리키고 있는 주소 값 : %d\n", &v[0]);
    printf("v.capacity() : %d\n", v.capacity());
    printf("///////////////////cut//////////////////\n");


    printf("///////////////////이동생성자//////////////////\n");
    v.push_back(move(a));
    v[0].print();
    printf("벡터가 가르키고 있는 주소 값 : %d\n", &v[0]);
    printf("v.capacity() : %d\n", v.capacity());

    v.push_back(move(b));
    v[0].print();
    printf("벡터가 가르키고 있는 주소 값 : %d\n", &v[0]);
    printf("v.capacity() : %d\n", v.capacity());
    printf("///////////////////cut//////////////////\n");
    return 0;
}