
// DiglogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Diglog.h"
#include "DiglogDlg.h"
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


// CDiglogDlg 대화 상자



CDiglogDlg::CDiglogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIGLOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDiglogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTCTRL, m_ListCtrl);
	DDX_Control(pDX, IDC_TREE_CONTROL, m_Tree);
}

BEGIN_MESSAGE_MAP(CDiglogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDiglogDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_LISTCTRL_ADD, &CDiglogDlg::OnBnClickedListctrlAdd)
	ON_BN_CLICKED(IDC_LISTCTRL_DEL, &CDiglogDlg::OnBnClickedListctrlDel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTCTRL, &CDiglogDlg::OnLvnItemchangedListctrl)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CDiglogDlg::OnDeltaposSpin1)
END_MESSAGE_MAP()


// CDiglogDlg 메시지 처리기

BOOL CDiglogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	spin_value = 0;

	HTREEITEM root, hChild1, hChild2;

	root = m_Tree.InsertItem(TEXT("root"), 0, 0, TVI_ROOT, TVI_LAST);
	hChild1 = m_Tree.InsertItem(TEXT("첫번째항목"), 0, 0, root, TVI_LAST);
	hChild2 = m_Tree.InsertItem(TEXT("두번째항목"), 0, 0, root, TVI_LAST);
	m_Tree.InsertItem(TEXT("첫번째하위항목"), 0, 0, hChild1, TVI_LAST);
	m_Tree.InsertItem(TEXT("두번째하위항목"), 0, 0, hChild2, TVI_LAST);
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

	CRect rt;
	m_ListCtrl.GetWindowRect(&rt);
	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_ListCtrl.InsertColumn(0, TEXT("순번"), LVCFMT_LEFT, rt.Width()*0.3);
	m_ListCtrl.InsertColumn(1, TEXT("항목"), LVCFMT_CENTER, rt.Width() * 0.3);
	m_ListCtrl.InsertColumn(2, TEXT("내용"), LVCFMT_CENTER, rt.Width() * 0.3);
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDiglogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDiglogDlg::OnPaint()
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
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDiglogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDiglogDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CDiglogDlg::OnBnClickedListctrlAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ListCtrl.GetItemCount();
	CString str;
	str.Format(_T("%d"), num);

	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, TEXT("test"), NULL, NULL, NULL, NULL);

	CString str2;
	GetDlgItemTextW(IDC_LISTCTRL_EDIT, str2);

	m_ListCtrl.SetItem(num, 2, LVIF_TEXT, str2, NULL, NULL, NULL, NULL);
}


void CDiglogDlg::OnBnClickedListctrlDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	int idx = m_ListCtrl.GetNextSelectedItem(pos);
	m_ListCtrl.DeleteItem(idx);
 }


void CDiglogDlg::OnLvnItemchangedListctrl(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CDiglogDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (pNMUpDown->iDelta < 0)
	{
		spin_value++;
	}
	else
	{
		spin_value--;
	}

	SetDlgItemInt(IDC_EDIT_SPIN, spin_value);
	*pResult = 0;
}
