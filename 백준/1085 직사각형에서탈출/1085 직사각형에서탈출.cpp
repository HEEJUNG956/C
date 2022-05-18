#include <iostream>
using namespace std;

int x, y, w, h;
int main()
{
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int answer1 = min(x, y);
    int answer2 = min(w - x, h - y);
    printf("%d", min(answer1, answer2));
}
