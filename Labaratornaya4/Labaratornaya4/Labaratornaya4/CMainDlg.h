
// CMainDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// диалоговое окно CMainDlg
class CMainDlg : public CDialog
{
// Создание
public:
	CMainDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_LABARATORNAYA4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	HICON Diamand;
	HICON Clover;
	HICON Hearth;
	HICON Pike;
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedPLAY();

	BOOL m_AllIn;
	afx_msg void OnClickedCheck1();

	CString m_Stavka;
	CString m_Balance;
	//CString Edit3Val;
	afx_msg void OnBnClickedRESET();
	void ChangeCard(int r,CStatic &Card);
	CListCtrl m_Report;
	CStatic m_Card1;
	CStatic m_Card2;
	CStatic m_Card3;
	CStatic m_Card4;
	afx_msg void OnBnClickedCancel();
};
