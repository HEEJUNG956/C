
// 채팅프로그램Dlg.h: 헤더 파일
//

#pragma once

#include "stdAfx.h"

// C채팅프로그램Dlg 대화 상자
class C채팅프로그램Dlg : public CDialogEx
{
// 생성입니다.
public:
	C채팅프로그램Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CSocServer m_socServer; // 서버용 소켓
	CSocCom* m_socCom;		// 통신용 소켓

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

	

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LPARAM OnAccept(UINT wParam, LPARAM lParam);
	afx_msg LPARAM OnReceive(UINT wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strSend;
	CListBox m_list;
	CString m_strStatus;
	afx_msg void OnClickedButtonSend();
};
