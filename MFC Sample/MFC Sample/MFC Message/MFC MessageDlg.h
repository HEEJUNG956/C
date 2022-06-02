
// MFC MessageDlg.h: 헤더 파일
//

#pragma once


// CMFCMessageDlg 대화 상자
class CMFCMessageDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCMessageDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_MESSAGE_DIALOG };
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

	// 사용자 메시지를 사용할 때 발생한 메시지 핸들러 생성
	afx_msg LRESULT OnMyTestMessage(WPARAM wParam, LPARAM lPararm);

	DECLARE_MESSAGE_MAP()
};
