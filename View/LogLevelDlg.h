#pragma once

#include"resource.h"
#include"dll\Table.h"
#include"dll\Logger.h"
#include "afxwin.h"
// LogLevelDlg dialog

class LogLevelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LogLevelDlg)

public:
	LogLevelDlg(Logger *logger,CWnd* pParent = NULL);   // standard constructor
	virtual ~LogLevelDlg();
	BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	Logger *log;
	DECLARE_MESSAGE_MAP()
public:
	CComboBox log_level_combo_c;
	afx_msg void OnBnClickedButton1();
};
