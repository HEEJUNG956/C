#include <iostream>
#include <ShlObj_core.h>
using namespace std;
int main()
{
    PWSTR path = NULL;
    SHGetKnownFolderPath(FOLDERID_Desktop, 0, NULL, &path);

    wprintf(L"%s\n", path);
    CoTaskMemFree(path);

    SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path);
    wprintf(L"%s\n", path);
    CoTaskMemFree(path);
    return 0;
}

