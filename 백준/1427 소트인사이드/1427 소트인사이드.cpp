#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 미해결

int main()
{
    string t;
    cin >> t;
    sort(t.begin(), t.end(), greater<char>());
    cout << t;
}

