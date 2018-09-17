
// CMainDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// ���������� ���� CMainDlg
class CMainDlg : public CDialog
{
// ��������
public:
	CMainDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_LABARATORNAYA4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;
	HICON Diamand;
	HICON Clover;
	HICON Hearth;
	HICON Pike;
	// ��������� ������� ����� ���������
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
