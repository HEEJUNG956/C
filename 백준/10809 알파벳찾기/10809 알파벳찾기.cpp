#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 미해결

int main()
{
    string temp;
    getline(cin, temp);
    int max = 0, cnt = 0, target;
    int a[26] = { 0 };
    transform(temp.begin(), temp.end(), temp.begin(),(int(*)(int))toupper);

    for (int i = 0; i < temp.length(); i++)
    {
        a[temp[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            cnt = 0;
            target = i;
        }
        if (max == a[i])
            cnt++;
    }
    if (cnt > 1)
        printf("?");
    else
        printf("%c", (char)(target + 'A'));
    return 0;
}
