#include <iostream>
using namespace std;
int main()
{
    int x1, y1, r1, x2, y2, r2, d, cond1, cond2, t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        cond1 = (r1 - r2) * (r1 - r2);
        cond2 = (r1 + r2) * (r1 + r2);

        if (d == 0)
        {
            if (cond1 == 0)
                printf("-1\n");
            else
                printf("0\n");
        }
        else if (d == cond1 || d == cond2)
            printf("1\n");
        else if (cond1 < d && d < cond2)
            printf("2\n");
        else
            printf("0\n");
    }
}
