#include <iostream> 
#include <string> 
#include <ctime>
#include <cstdlib> 
#include <Windows.h>
using namespace std; 


int main() 
{ 
    srand(time(NULL)); 
    char ch; string list[]= {"apple","bear","banana","happy"}; 
    int r =rand()%5; 
    int life = 10;
    string str = list[r]; 
    string res(str.length(),'_'); 
    
    while(1)
    { 
            printf("남은 생명 : % d \n", life);
            cout << "문자를 맞춰보세요 : ";
            cout << res << endl;
            cout<<"문자를 입력 : "; 
            cin >> ch; 
            for(int i=0; i<str.length(); i++)
            { 
                if(ch==str[i])
                { 
                    res[i]=ch; 
                } 
                else
                {
                    life--;
                }
            } 
        

            if(str== res)
            { 
                cout<<"성공"<<endl; break; 
            } 
            
            system("PAUSE");
            system("cls");
    } 
    return 0;
}

