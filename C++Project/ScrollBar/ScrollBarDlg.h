
// ScrollBarDlg.h: 헤더 파일
//

#pragma once


// CScrollBarDlg 대화 상자
class CScrollBarDlg : public CDialogEx
{
// 생성입니다.
public:
	CScrollBarDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	POINT c;
	POINT origin;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCROLLBAR_DIALOG };
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
	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	DECLARE_MESSAGE_MAP()
public:
	CScrollBar m_Vscroll;
	CScrollBar m_HScroll;
protected:
//	afx_msg LRESULT OnAaaa(WPARAM wParam, LPARAM lParam);
	afx_msg
		void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	LRESULT OnHscroll(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnVscroll(WPARAM wParam, LPARAM lParam);
};
