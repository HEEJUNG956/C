#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int count = 0;

    if (str.empty())
    {
        printf("0");
        return 0;
    }
    count = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            count++;
    }
    if (str[0] == ' ')
        count--;
    if (str[str.length() - 1] == ' ')
        count--;
    printf("%d", count);
    return 0;
}