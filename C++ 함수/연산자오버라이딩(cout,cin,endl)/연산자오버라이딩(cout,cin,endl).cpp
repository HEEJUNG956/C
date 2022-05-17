#include <iostream>
using namespace std;

// 사용하는 이유는 함수객체 때문
// 사용자가 원하는 대로 효율적으로 재정의가 가능하여
// 범용성과 효율성이 높아서 사용
class Point
{
    int xpos, ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y){}

    // friend 선언 이유는 point의 xpos,ypos가 private이어서
    friend ostream& operator <<(ostream&, const Point&);
};

ostream& operator << (ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' ;
    return os;
}
int main()
{
    Point pos(1, 2);
    cout << pos << "\n";
    return 0;
}
