#include<iostream> 
#include<ctime>
#include<cstdlib>
#include<Windows.h> 
#include<conio.h>

using namespace std;

const int UP = 72; 
const int DOWN = 80; 
const int LEFT = 75; 
const int RIGHT = 77; 

const int NOTBOMB = -2; 
const int BOMB = -1; 
const int BORDER = -3; 
const int FLAG = -4;

const int EASY_SIZE = 12; 
const int NORMAL_SIZE = 17; 
const int HARD_SIZE = 22; 

const int EASY_BOMB_COUNT = 5; 
const int NORMAL_BOMB_COUNT = 25; 
const int HARD_BOMB_COUNT = 55; 

const int EASY_MODE = 1; 
const int NORMAL_MODE = 2; 
const int HARD_MODE = 3;

void Init(int** map, int** check, int size, int bomb);
void Print(int** map, int** check, int size, int mode);
void AroundBomb(int** map, int size);

void gotoxy(int x, int y);
void setColor(int color, int bgcolor);
void PLAY(int** map, int** check, int mode);

int main(void)
{
    int menu;
    srand((unsigned)time(NULL));
    setColor(15, 0);
    system("cls");
    while (1)
    {
        system("mode con:cols=60 lines=43");
        gotoxy(10, 10); 
        setColor(13, 0); 
        cout << endl; 
        cout << "\t << M E N U >> \t" << endl; 
        cout << endl; setColor(15, 0); 
        cout << "\t 1. 초급 모드 ( 10 × 10 )\t" << endl; 
        cout << endl; 
        cout << "\t 2. 중급 모드 ( 15 × 15 )\t" << endl; 
        cout << endl; 
        cout << "\t 3. 고급 모드 ( 20 × 20 )\t" << endl; 
        cout << endl; 
        cout << "\t 4. 종료 하기\t" << endl; 
        cout << endl; 
        setColor(13, 0); 
        cout << "\t 메뉴를 입력하세요 : "; 
        cin >> menu; setColor(15, 0); 
        system("cls"); 
        if (menu == 4) break; 
        switch (menu)
        {
        case1:
            {
                
            }
        case2:
            {

            }
        case3:
            {

            }
        case4:
            {
                break;
            }
        }

      
    }

}