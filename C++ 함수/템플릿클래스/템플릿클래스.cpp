#include <iostream>
using namespace std;

template <class T>
class Calculator
{
private:
    T x, y;
public :
    Calculator(T n1, T n2) : x(n1), y(n2){}
    T Adder();
};

template<class T>
T Calculator<T>::Adder()
{
    return x + y;
}

int main()
{
    Calculator<int> cal1(10, 20);
    Calculator<double> cal2(1.5, 20.9999);
    
    printf("%d\n", cal1.Adder());
    printf("%f\n", cal2.Adder());
    return 0;
}
