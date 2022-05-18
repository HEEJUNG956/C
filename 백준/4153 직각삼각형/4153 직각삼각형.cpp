#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0)
            break;
        if(max(a,b) == a)
            if (max(a, c) == a)
            {
                if (a * a == b * b + c * c) printf("right\n");
                else printf("wrong\n");
            }
            else
            {
                if (c * c == a * a + b * b) printf("right\n");
                else printf("wrong\n");
            }
        else
            if (max(b, c) == b)
            {
                if (b * b == a * a + c * c) printf("right\n");
                else printf("wrong\n");
            }
            else
            {
                if (c * c == a * a + b * b) printf("right\n");
                else printf("wrong\n");
            }
    }
}
