#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <shlobj_core.h>

using namespace std;
string text = "성자신손 오백 년은 우리 황실이요\
산수 고려 동반도는 우리 본국일세\
무궁화 삼천리 화려강산\
조선 사람 조선으로 길이 보존하세\
이천만 오직 한 마음 나라 사랑하여\
사농공상 상하 없이 제 직분 다하세\
무궁화 삼천리 화려강산\
조선 사람 조선으로 길이 보존하세";


void create_filename(PWSTR path, WCHAR* cp_path, string s)
{
    int i = 0;
    while (path[i] != '\0') cp_path[i] = path[i++];
    for_each(s.begin(), s.end(), [&](char& c) {cp_path[i++] = c;});
    cp_path[i] = '\0';
}
int main()
{
    PWSTR path = NULL; WCHAR cp_path[100];
    SHGetKnownFolderPath(FOLDERID_Desktop, 0, NULL, &path);
    create_filename(path, cp_path, "\\text.txt");

    ofstream writeFile(cp_path);
    if (writeFile.is_open())
    {
        writeFile << text;
        writeFile.close();
    }

    ifstream readFile(cp_path);

    if (readFile.is_open())
    {
        string line;
        while (getline(readFile, line))
        {
            printf("%s\n", line.c_str());
        }
        readFile.close();
    }

    CoTaskMemFree(path);
    return 0;
}

