#pragma once
#include"resource.h"
#include "afxwin.h"
#include"dll\Table.h"
#include"dll\Logger.h"
// LogInsertDlg dialog

class LogInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LogInsertDlg)

public:
	LogInsertDlg(Logger *logger,CWnd* pParent = NULL);   // standard constructor
	virtual ~LogInsertDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };
	BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	Logger *log;
	DECLARE_MESSAGE_MAP()
public:
	CComboBox log_type_combo_c;
	CEdit log_text_c;
	afx_msg void OnBnClickedButton1();
};
