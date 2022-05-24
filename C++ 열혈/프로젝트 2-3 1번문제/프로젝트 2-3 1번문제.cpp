#include <iostream>
#pragma warning (disable:4996)
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
    Point* result = new Point;
    result->xpos = p1.xpos + p2.xpos;
    result->ypos = p1.ypos + p2.ypos;
    return *result;
}

int main()
{
    Point* ptr1 = new Point;
    printf("ptr1의 xpos와 ypos의 입력 : ");
    scanf("%d %d", ptr1->xpos, ptr1->ypos);

    Point* ptr2 = new Point;
    printf("ptr2의 xpos와 ypos의 입력 : ");
    scanf("%d %d", ptr2->xpos, ptr2->ypos);

    Point& result = PntAdder(*ptr1, *ptr2);
    printf("결과의 xpos : %d\n", result.xpos);
    printf("결과의 ypos : %d\n", result.ypos);

    delete ptr1;
    delete ptr2;
    delete& result;
    return 0;
}