#include <iostream>
using namespace std;
int main()
{
    int num, yy, xx;
    scanf("%d", &num);
    int* h = new int[num];
    int* w = new int[num];
    int* order = new int[num];
    for (int i = 0; i < num; i++)
        scanf("%d %d %d", &h[i], &w[i], &order[i]);
    for (int i = 0; i < num; i++)
    {
        xx = order[i] / h[i] + 1;
        yy = order[i] % h[i];
        if (order[i] % h[i] == 0)
        {
            yy = h[i];
            xx--;
        }
        if (xx < 10)
            printf("%d%02d\n", yy, xx);
        else
            printf("%d%d\n", yy, xx);
    }

    //int t, h, w, n;
    //scanf("%d", &t);
    //while (t--)
    //{
    //    scanf("%d %d %d", &h, &w, &n);
    //    printf("%d%02d\n", (n - 1) % h + 1, (n - 1) / h + 1);
    //}
}
