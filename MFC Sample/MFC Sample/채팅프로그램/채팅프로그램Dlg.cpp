﻿
// 채팅프로그램Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "채팅프로그램.h"
#include "채팅프로그램Dlg.h"
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


// C채팅프로그램Dlg 대화 상자



C채팅프로그램Dlg::C채팅프로그램Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_strSend(_T(""))
	, m_strStatus(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C채팅프로그램Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT_SEND, m_strSend);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//DDX_Control(pDX, IDC_STATIC_STATUS, m_strStatus);
}

BEGIN_MESSAGE_MAP(C채팅프로그램Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(UM_ACCEPT, OnAccept)
	ON_MESSAGE(UM_RECEIVE, OnReceive)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &C채팅프로그램Dlg::OnClickedButtonSend)
END_MESSAGE_MAP()


// C채팅프로그램Dlg 메시지 처리기

BOOL C채팅프로그램Dlg::OnInitDialog()
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
	m_socCom = NULL;
	// 서버 소켓을 생성 (포트번호 5000)
	m_socServer.Create(5000);
	// 클라이언트의 접속을 기다림
	m_socServer.Listen();
	// 소켓 클래스와 메인 윈도우(여기에서는 CChatServerDlg)를 연결
	m_socServer.Init(this->m_hWnd);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void C채팅프로그램Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C채팅프로그램Dlg::OnPaint()
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
HCURSOR C채팅프로그램Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C채팅프로그램Dlg::OnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	char pTmp[256];
	CString strTmp;

	memset(pTmp, '\0', 256);
	//strcpy_s(pTmp, m_strSend);
	m_strSend = "";

	m_socCom->Send(pTmp, 256);

	//strTmp.Format("%s", pTmp);
	int i = m_list.GetCount();
	m_list.InsertString(i, strTmp);

	UpdateData(FALSE);
}


LPARAM C채팅프로그램Dlg::OnAccept(UINT wParam, LPARAM lParam)
{
	// 클라이언트에서 접속 요청이 왔을때
	m_strStatus = "접속성공";
	
	// 통신용 소켓을 생성한뒤
	m_socCom = new CSocCom;
	// 서버 소켓과 통신 소켓을 연결한다.
	m_socCom = m_socServer.GetAcceptSocCom();
	m_socCom->Init(this->m_hWnd);

	// 소켓이 연결되었다는 것을 클라이언트에 알리기 위해서 Send함수로 "접속성공"이라고 보냄
	m_socCom->Send("접속 성공", 256);

	UpdateData(FALSE);
	return TRUE;
}

// 데이터를 보내는 것은 소켓 클래스의 멤버 함수인 Send를 이용
// 데이터를 받을 때는 통신 소켓 클래스에 오버라이딩한 OnReceive 메시지
LPARAM C채팅프로그램Dlg::OnReceive(UINT wParam, LPARAM lParam)
{
	char pTmp[256];
	CString strTmp;
	memset(pTmp, '\0', 256);

	// 데이터를 pTmp에 받는다.
	m_socCom->Receive(pTmp, 256);
	//strTmp.Format("%s", pTmp);

	// 리스트 박스에 보여준다.
	int i = m_list.GetCount();
	m_list.InsertString(i, strTmp);
	return TRUE;
}


