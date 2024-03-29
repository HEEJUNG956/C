﻿
// MFCDlg.h: 헤더 파일
//

#pragma once


// CMFCDlg 대화 상자
class CMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DIALOG };
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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonTest();
	CString m_strEdit;
	CStatic m_staticTest;
	CListCtrl m_listTest;
	afx_msg void OnLvnItemchangedListTest(NMHDR* pNMHDR, LRESULT* pResult);
};
