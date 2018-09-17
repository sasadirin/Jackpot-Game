
// CMainDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Labaratornaya4.h"
#include "CMainDlg.h"
#include "afxdialogex.h"
#include <ctime>
#include <cstdlib>
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// диалоговое окно CMainDlg

	

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
	, m_Stavka(_T(""))
	, m_AllIn(FALSE)
	, m_Balance(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Diamand=AfxGetApp()->LoadIcon(IDI_DIAMAND);
	Clover=AfxGetApp()->LoadIcon(IDI_CLOVER);
	Hearth=AfxGetApp()->LoadIcon(IDI_HEARTH);
	Pike=AfxGetApp()->LoadIcon(IDI_PIKE);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STAVKA, m_Stavka);
	DDX_Check(pDX, IDC_CHECK1, m_AllIn);
	DDX_Text(pDX, IDC_BALANCE, m_Balance);
	DDX_Control(pDX, IDC_REPORT, m_Report);
	DDX_Control(pDX, IDC_CARD1, m_Card1);
	DDX_Control(pDX, IDC_CARD2, m_Card2);
	DDX_Control(pDX, IDC_CARD3, m_Card3);
	DDX_Control(pDX, IDC_CARD4, m_Card4);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMainDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_PLAY, &CMainDlg::OnBnClickedPLAY)
	ON_BN_CLICKED(IDC_CHECK1, &CMainDlg::OnClickedCheck1)
	ON_BN_CLICKED(IDC_RESET, &CMainDlg::OnBnClickedRESET)
	ON_BN_CLICKED(IDCANCEL, &CMainDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// обработчики сообщений CMainDlg

BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_Balance="100";
	m_Stavka="";

	m_Card1.SetIcon(Clover);
	m_Card2.SetIcon(Diamand);
	m_Card3.SetIcon(Hearth);
	m_Card4.SetIcon(Pike);

	UpdateData(FALSE);

	m_Report.InsertColumn(0,L"История изменений баланса",0,225);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMainDlg::OnBnClickedOk()
{
	CDialog::OnOK();
}



void CMainDlg::OnBnClickedPLAY()
{
	GetDlgItem(IDC_PLAY)->EnableWindow(SW_HIDE);
	UpdateData(TRUE);
	int St,Bal,BalH;
	St=_wtoi(m_Stavka);
	Bal=_wtoi(m_Balance);
	BalH=Bal;
	if(m_AllIn){
		St=Bal;
		m_Stavka=m_Balance;
		m_Balance="0";
		UpdateData(FALSE);
	}

	if(St>Bal){
		MessageBox(L"Ваша ставка больше вашего баланса",L"Error",MB_ICONERROR);
		return;
	}

	if(m_Stavka=="" && !m_AllIn){
		MessageBox(L"Введите ставку",L"Error",MB_ICONERROR);
		return;
	}

	srand(time(nullptr));

	CStatic *arCards[4]={&m_Card1,&m_Card2,&m_Card3,&m_Card4};
	
	int v[4];
	

	
	
	int startT=clock();

	while((clock()-startT)<2000){
		while((clock()-startT)<500){}

		for(int i=0;i<4;i++){
			v[i]=rand() %4+0;
			
			ChangeCard(v[i],*arCards[i]);
		}
	}

	
	if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3]){
		Bal=Bal+(10*St);
		m_Stavka.Format(L"");
		m_Balance.Format(L"%d",Bal);
		UpdateData(FALSE);
	}

	else if(v[0]==v[1] && v[1]==v[2] ){
		Bal=Bal+(5*St);
		m_Stavka.Format(L"");
		m_Balance.Format(L"%d",Bal);
		UpdateData(FALSE);
	}

	else if(v[0]==v[1] ){
		Bal=Bal+(2*St);
		m_Balance.Format(L"%d",Bal);
		m_Stavka.Format(L"");
		UpdateData(FALSE);
	}

	else{
		Bal-=St;
		m_Stavka.Format(L"");
		m_Balance.Format(L"%d",Bal);
		UpdateData(FALSE);
	}
	BalH=Bal-BalH;
	CString History;
	History.Format(L"Ваша ставка %d ,выигрышь %d",St,BalH);
	m_Report.InsertItem(0,History,-1);
	GetDlgItem(IDC_PLAY)->EnableWindow(SW_SHOW);

}


void CMainDlg::OnClickedCheck1()
{
	if(!m_AllIn){
		GetDlgItem(IDC_STAVKA)->EnableWindow(SW_HIDE);
		m_AllIn=TRUE;
	}
	else{	
		
		GetDlgItem(IDC_STAVKA)->EnableWindow(SW_SHOW);
		m_AllIn=FALSE;
	}

}

void CAboutDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}





void CMainDlg::OnBnClickedRESET()
{
	// TODO: добавьте свой код обработчика уведомлений
	
	m_Balance="100";
	m_Stavka="";
	GetDlgItem(IDC_STAVKA)->EnableWindow(SW_SHOW);
	m_AllIn=FALSE;
	m_Card1.SetIcon(Clover);
	m_Card2.SetIcon(Diamand);
	m_Card3.SetIcon(Hearth);
	m_Card4.SetIcon(Pike);
	UpdateData(FALSE);
	
	m_Report.DeleteAllItems();

}

void CMainDlg::ChangeCard(int r,CStatic &Card){
	switch(r){
	case 1:
		Card.SetIcon(Clover);
		break;
	case 2:
		Card.SetIcon(Diamand);
		break;
	case 3:
		Card.SetIcon(Hearth);
		break;
	case 0:
		Card.SetIcon(Pike);
		break;
	default:
		break;
	}

}
;




void CMainDlg::OnBnClickedCancel()
{
	CString c;
	c.Format(L"Отличная игра ! Ваш выигрышь: %s , приходите еще! ",m_Balance);
	MessageBox(c,L"Прощание",MB_OK);
	// TODO: добавьте свой код обработчика уведомлений
	CDialog::OnCancel();
}
