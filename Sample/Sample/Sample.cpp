#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("test.txt");
    fout << 1 << ' ' << 2 << '\t' << 3 << '\n' << 4;

    return 0;
}