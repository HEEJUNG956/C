#include <iostream>
using namespace std;

struct MyStruct
{
    int num1;
    char arr1[10];
    
    void print(void)
    {
        printf("My Struct\n");
        printf("num = %d\n", num1);
        printf("arr[0] = %c\n", arr1);
    }
};

class MyClass
{
public:
    int num2;
    char arr2[10];

    void print(void)
    {
        printf("My Struct\n");
        printf("num = %d\n", num2);
        printf("arr[0] = %c\n", arr2);
    }
};
int main()
{
    MyStruct m = { 10, "MY" };
    m.print();

    MyClass c = { 10, "MY" };
    c.print();

    return 0;
}

