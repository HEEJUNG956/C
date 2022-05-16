#include <iostream>

    // 미해결

int main()
{
    int number;
    scanf("%d", &number);
    int i = 0;
    for (int sum = 2; sum <= number; i++)
        sum += 6 * i;
    if (number == 1)
        i = 1;
    printf("%d", i);
    return 0;
}
