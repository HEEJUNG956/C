﻿#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 미해결

int main()
{
    int num;
    scanf("%d", &num);
    string *str;
    str = new string[num];
    int idx[26] = { 0};
    bool status = true;
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < num; i++)
    {
        status = true;
        memset(idx, 0, sizeof(idx));
        for (int j = 0; j < str[i].length(); j++)
        {
            if(idx[str[i][j] - 'a'] != 0)
                if (str[i][j - 1] != str[i][j])
                {
                    status = false;
                    break;
                }
            idx[str[i][j] - 'a']++;
        }
        if (status)
            count++;
    }
    printf("%d", count);
}
