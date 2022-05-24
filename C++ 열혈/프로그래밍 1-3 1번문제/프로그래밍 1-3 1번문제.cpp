#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int BoxVolume(int num1, int num2, int num3);
int BoxVolume(int num1, int num2);
int BoxVolume(int num1);

int main()
{
    std::cout << "[3, 3, 3]: " << BoxVolume(3, 3, 3) << std::endl;

    std::cout << "[5, 5, D]: " << BoxVolume(5, 5) << std::endl;

    std::cout << "[7, D, D]: " << BoxVolume(7) << std::endl;
    return 0;
}

int BoxVolume(int num1, int num2, int num3)
{
    return num1 * num2 * num3;
}

int BoxVolume(int num1, int num2)
{
    return num1 * num2 * 1;
}

int BoxVolume(int num1)
{
    return num1 * 1 * 1;
}


