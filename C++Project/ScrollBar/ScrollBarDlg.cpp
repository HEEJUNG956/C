
// ScrollBarDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ScrollBar.h"
#include "ScrollBarDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CScrollBarDlg 대화 상자



CScrollBarDlg::CScrollBarDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCROLLBAR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScrollBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_Vscroll);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_HScroll);
}

BEGIN_MESSAGE_MAP(CScrollBarDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_MESSAGE(aa, &CScrollBarDlg::OnAaaa)
ON_MESSAGE(WM_HSCROLL, &CScrollBarDlg::OnHscroll)
ON_MESSAGE(WM_VSCROLL, &CScrollBarDlg::OnVscroll)
END_MESSAGE_MAP()


// CScrollBarDlg 메시지 처리기

BOOL CScrollBarDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	CRect VScroll;
	CRect HScroll;

	m_Vscroll.GetWindowRect(&VScroll);
	m_HScroll.GetWindowRect(&HScroll);

	m_Vscroll.SetScrollRange(0, VScroll.Height());
	m_HScroll.SetScrollRange(0, HScroll.Width());

	c.x = 0;
	c.y = 0;

	origin.x = HScroll.left;
	origin.y = VScroll.top;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CScrollBarDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CScrollBarDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CClientDC DC(this);
		POINT t;
		t.x = c.x + origin.x;
		t.y = c.y + origin.y;

		DC.Ellipse(t.x, t.y, t.x + 10, t.y + 10);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CScrollBarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CScrollBarDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar->GetSafeHwnd() == m_HScroll.GetSafeHwnd())
	{
		int pos;
		pos = m_HScroll.GetScrollPos();
		if (nSBCode == SB_LINEUP) m_HScroll.SetScrollPos(pos + 10);
		else if (nSBCode == SB_LINEUP) m_HScroll.SetScrollPos(pos - 10);
		else if (nSBCode == SB_PAGEUP) m_HScroll.SetScrollPos(pos - 50);
		else if (nSBCode == SB_PAGEDOWN) m_HScroll.SetScrollPos(pos + 50);
		else if (nSBCode == SB_THUMBTRACK) m_HScroll.SetScrollPos(nPos);

		c.x = m_HScroll.GetScrollPos();
		OnPaint();
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CScrollBarDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar->GetSafeHwnd() == m_Vscroll.GetSafeHwnd())
	{
		int pos;
		pos = m_Vscroll.GetScrollPos();

		if (nSBCode == SB_LINEDOWN) m_Vscroll.SetScrollPos(pos + 10);
		else if (nSBCode == SB_LINEUP) m_Vscroll.SetScrollPos(pos - 10);
		else if (nSBCode == SB_PAGEUP) m_Vscroll.SetScrollPos(pos - 50);
		else if (nSBCode == SB_PAGEDOWN) m_Vscroll.SetScrollPos(pos + 50);
		else if (nSBCode == SB_THUMBTRACK) m_Vscroll.SetScrollPos(nPos);

		c.y = m_Vscroll.GetScrollPos();
		OnPaint();
		CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
	}
}

afx_msg LRESULT CScrollBarDlg::OnHscroll(WPARAM wParam, LPARAM lParam)
{
	return 0;
}


afx_msg LRESULT CScrollBarDlg::OnVscroll(WPARAM wParam, LPARAM lParam)
{
	return 0;
}
