﻿#include <stdio.h>
#include <windows.h>

int main()
{
    int a;
    while (1) {
        printf("숫자입력(1:초기화, 2: 종료) : ");
        scanf("%d", &a);
        if (a == 1) {
            system("cls");
        }
        else if (a == 2) {
            break;
        }
    }
}