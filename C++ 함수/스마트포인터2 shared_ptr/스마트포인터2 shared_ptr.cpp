#include <iostream>
#include <memory>
using namespace std;
// shared_ptr 하나의 변수를 동시에 참조가 가능
class A {
private:
    int* num;
public:
    A() : num(new int[100]){}

    ~A() {
        printf("소멸자~\n");
        delete[] num;
    }

    void print_ptr() { printf("%x\n", num); }
};
int main()
{
    shared_ptr<A> sh_p1 = make_shared<A>();
    shared_ptr<A> sh_p2 = sh_p1;
    sh_p1->print_ptr();
    sh_p2->print_ptr();
}
