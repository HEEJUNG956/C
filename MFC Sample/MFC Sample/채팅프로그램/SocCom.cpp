// SocCom.cpp: 구현 파일
//

#include "pch.h"
#include "채팅프로그램.h"
#include "SocCom.h"

// CSocCom 멤버함수
// 소켓 클래스와 메인윈도우를 연결시킴

void CSocCom::Init(HWND hWnd)
{
	m_hWnd = hWnd;
}


void CSocCom::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	SendMessage(m_hWnd, UM_RECEIVE, 0, 0);
	CSocket::OnReceive(nErrorCode);
}
