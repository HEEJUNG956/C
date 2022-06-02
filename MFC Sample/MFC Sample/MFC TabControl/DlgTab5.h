#pragma once
#include "afxdialogex.h"


// CDlgTab5 대화 상자

class CDlgTab5 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab5)

public:
	CDlgTab5(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgTab5();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
