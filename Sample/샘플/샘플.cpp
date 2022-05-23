
#include  <iostream>
#include  <string>
using namespace std;



int main()
{

    int player, ai;
    string a;//플레이의 선택한 수를 문자로 보여주기 위함

    while (true)
    {
        cout << "0. 가위" << endl;
        a = "가위";

        cout << "1. 바위" << endl;
        a = "바위";

        cout << "2. 보" << endl;
        a = "보";

        cout << "4. 종료" << endl;
        cout << "선택 하시오" << endl;

        cin >> player;

        switch (player)
        {
        case 0:
            cout << "플레이어 >> 가위" << endl;
            break;
        case 1:
            cout << "플레이어 >> 바위" << endl;
            break;
        case 2:
            cout << "플레이어 >> 보" << endl;
            break;
        }

        if (player < 1 || player > 4) // 1~4번 외 다른 입력을 했을 경우
        {
            cout << "잘못 입력 했습니다." << endl;
            system("pause");//일지정지
            continue; //반복문의 시작점으로 이동 시켜주는 기능
        }

        else if (player == 4)
        {
            break;//반복문에서 빠져나감 즉 종료
        }

        ai = rand() % 3;//로봇이 선택한 수

        switch (ai)
        {
        case 0:
            cout << "컴퓨터 >> 가위" << endl;
            break;
        case 1:
            cout << "컴퓨터 >> 바위" << endl;
            break;
        case 2:
            cout << "컴퓨터 >> 보" << endl;
            break;
        }

        int win = player - ai;

        if (win == 1 || win == -2)  //플레이어의 값과 컴퓨터의 값을 뻈을떄 1이나 -2가 나왔을 경우 플레이어 승리
            cout << "player 승리!" << endl;
        else if (win == 0) //플레이어의 값과 컴퓨터의 값을 뻈을떄 0이 나왔을 경우 플레이어 승리
            cout << "비겼음!" << endl;
        else //0 ~ -2 외에 값이 나왔을 경우 ai 승리
            cout << "ai 승리!" << endl;

        //예) 플레이어가 1(바위)냈을떄 ai가 1를 냈다고 하면 1-1 이니까 결과값은 0이고 0의 조건 결과값인 비겼음이 출력됨
        //예) 플레이어가 1(바위)냈을떄 ai가 2를 냈다고 하면 1-2 이니까 결과값은 -1이고 -1은 else의 조건 결과값인 ai승리가 출력됨
        //예) 플레이어가 1(바위)냈을떄 ai가 0를 냈다고 하면 1-0 이니까 결과값은 1이고 1의 조건 결과값인 플레이어 승리가 출력됨

        system("pause");
    }

}