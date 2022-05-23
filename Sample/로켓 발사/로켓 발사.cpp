#include <iostream>
#include <string>
using namespace std;
int main()
{
    int temp = 15;
    for (;;)
    {
        printf("과제명 : 로켓\n");
        printf("--하늘----하늘-----하늘-----구름----구름\n");
        {
            for (int i = temp; i >= 0; i--)
                printf("%d\n", i);
            printf("  ▲ \n");
            printf("◁▤▷\n");
            printf(" ┘└ \n");
            printf("wwwww\n");
        }
     system("cls");
    }

    
     
}
