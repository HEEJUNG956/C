﻿
// MFC TabControlDlg.h: 헤더 파일
//

#pragma once
#include "DlgTab1.h"
#include "DlgTab2.h"
#include "DlgTab3.h"
#include "DlgTab4.h"
#include "DlgTab5.h"

// CMFCTabControlDlg 대화 상자
class CMFCTabControlDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCTabControlDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_TABCONTROL_DIALOG };
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
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
	CDlgTab1* dlg1;
	CDlgTab2* dlg2;
	CDlgTab3* dlg3;
	CDlgTab4* dlg4;
	CDlgTab5* dlg5;
};
