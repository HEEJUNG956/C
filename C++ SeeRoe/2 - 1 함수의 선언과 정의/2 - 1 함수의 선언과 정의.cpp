#include <iostream>
using namespace std;
int Plus(int x, int y);
float Plus(float x, float y);
char Plus(char x, char y);
double Plus(double x, double y);
int main()
{
    cout << Plus(3.5, 5.5) << endl;
    cout << Plus(3, 5) << endl;
    cout << Plus((float)3.5, (float)5.5) << endl;
    cout << Plus((char)65, (char)32) << endl;
    //return 0;
}


int Plus(int x, int y)
{
    return x + y;
}
float Plus(float x, float y)
{
    return x + y;
}
char Plus(char x, char y)
{
    return x + y;
}
double Plus(double x, double y)
{
    return x + y;
}
