#include <iostream>
#pragma warning(disable:4996)
using namespace std;
/*

우리가 구현하고자 하는 것은 '은행계좌 관리 프로그램'이다. 프로젝트 1단계에서는 C스타일로 구현하는 것을 목표로 한다
구현할 기능은 다음과 같다
1.계좌개설
2.입금
3.출금
4.전체고객 잔액조회



프로그램을 간결하게 하기 위해서 몇가지 가정
1.통장의 계좌번호는 중복되지 아니한다(중복검사 하지 않겠다는 뜻)
2.입금 및 출금액은 무조건 0보다 크다(입금 및 출금액의 오류검사 않겠다는 뜻)
3.고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액, 이렇게 세가지만 저장 및 관리한다
4.둘 이상의 고객 정보 저장을 위해서 배열을 사용한다
5.계좌번호는 정수의 형태이다
*/
int Menu(void);
void MakeBankAccount(void);
void Deposit(int money);
void Withdraw(int money);
void ShowAccountInfo(void);

typedef struct _BankAccount
{
    int AccountNumber;
    char Name[20];
    int money;
}BankAccount;

BankAccount Arr[10];
int AccountNum = 0;

int main()
{
    int money;
    while (1)
    {
        int sel = Menu();
        switch (sel)
        {
        case 1:
            MakeBankAccount();
            break;
        case 2:
            printf("입금할 금액 : ");
            scanf("%d", &money);
            Deposit(money);
            break;
        case 3:
            printf("출금할 금액 : ");
            scanf("%d", &money);
            Withdraw(money);
            break;
        case 4:
            ShowAccountInfo();
            break;
        case 5:
            return 0;
        default:
            printf("잘못된 번호를 입력하셨습니다");
        }
    }
    return 0;
}


int Menu(void)
{
    system("cls");
    int sel;
    printf("=============메뉴=============\n");
    printf("1. 계좌개설\n");
    printf("2. 입금\n");
    printf("3. 출금\n");
    printf("4. 계좌정보 전체출력\n");
    printf("5. 프로그램 종료\n");
    printf("선택 : ");
    scanf("%d", &sel);

    return sel;
}

void MakeBankAccount()
{
    printf("계좌번호 입력 : ");
    scanf("%d", &Arr[AccountNum].AccountNumber);
    printf("이름 입력 : ");
    scanf("%s", &Arr[AccountNum].Name);
    printf("잔액 입력 : ");
    scanf("%d", &Arr[AccountNum].money);
    AccountNum++;
}

void Deposit(int money)
{
    char name[20];
    printf("고객님의 성함을 입력해주세요 : ");
    scanf("%s", &name);
    for (int i = 0; i <= AccountNum; i++)
    {
        if (strcmp(name, Arr[i].Name) == 0)
        {
            Arr[i].money += money;
            printf("입금이 완료되었습니다.");
        }
    }
}

void Withdraw(int money)
{
    char name[20];
    printf("고객님의 성함을 입력해주세요 : ");
    scanf("%s", &name);
    for (int i = 0; i <= AccountNum; i++)
    {
        if (strcmp(name, Arr[i].Name) == 0)
        {
            Arr[i].money -= money;
            printf("출금이 완료되었습니다");
        }
    }
}

void ShowAccountInfo(void)
{
    for (int i = 0; i < AccountNum; i++)
    {
        printf("%d번째 고객님의 정보는 아래와 같습니다.\n", i + 1);
        printf("이름 : %s\n", Arr[i].Name);
        printf("계좌번호 : %d\n", Arr[i].AccountNumber);
        printf("잔액 : %d\n", Arr[i].money);
    }
}
