
// MFCApplication1Dlg.h : header file
//

#pragma once

#include"dll\Table.h"
#include"dll\Logger.h"
#include"dll\XML.h"
#include<map>
#include "afxwin.h"
#include "afxcmn.h"
#include "MyDialog.h"


// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// standard constructor
	std::map<int, Table*> database;
// Dialog Data
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
public:
	CString m_Edit;
	afx_msg void OnEnChangeEdit1();
	void GetDB(std::map<int, Table*>& ddatabase);
	afx_msg void OnBnClickedButton2();
	CButton m_EditC;
	CEdit m_Edit2;
	CListCtrl list_c;
	CEdit status_c;
	Logger *log;
	afx_msg void OnHelpCommands();
};
