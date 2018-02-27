// LogLevelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LogLevelDlg.h"
#include "afxdialogex.h"


// LogLevelDlg dialog

IMPLEMENT_DYNAMIC(LogLevelDlg, CDialogEx)

LogLevelDlg::LogLevelDlg(Logger* logger,CWnd* pParent /*=NULL*/)
	: CDialogEx(LogLevelDlg::IDD, pParent)
{
	log = logger;
}

LogLevelDlg::~LogLevelDlg()
{
}
BOOL LogLevelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	std::string level="DISABLE";
	std::wstring wlevel(level.begin(), level.end());
	log_level_combo_c.AddString(wlevel.c_str());
	level = "INFO";
	std::wstring wlevel2(level.begin(), level.end());
	log_level_combo_c.AddString(wlevel2.c_str());
	level = "BUFFER";
	std::wstring wlevel3(level.begin(), level.end());
	log_level_combo_c.AddString(wlevel3.c_str());
	level = "TRACE";
	std::wstring wlevel4(level.begin(), level.end());
	log_level_combo_c.AddString(wlevel4.c_str());
	level = "DEBUG";
	std::wstring wlevel5(level.begin(), level.end());
	log_level_combo_c.AddString(wlevel5.c_str());
	level = "ENABLE";
	std::wstring wlevel6(level.begin(), level.end());
	log_level_combo_c.AddString(wlevel6.c_str());
	log_level_combo_c.SetCurSel(1);
	return TRUE;
}
void LogLevelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, log_level_combo_c);
}


BEGIN_MESSAGE_MAP(LogLevelDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LogLevelDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// LogLevelDlg message handlers


void LogLevelDlg::OnBnClickedButton1()
{
	if (log_level_combo_c.GetCurSel() == 0)
	{
		log->updateLogLevel(DISABLE_LOG);
	}
	else if (log_level_combo_c.GetCurSel() == 1)
	{
		log->updateLogLevel(LOG_LEVEL_INFO);
	}
	else if (log_level_combo_c.GetCurSel() == 2)
	{
		log->updateLogLevel(LOG_LEVEL_BUFFER);
	}
	else if (log_level_combo_c.GetCurSel() == 3)
	{
		log->updateLogLevel(LOG_LEVEL_TRACE);
	}
	else if (log_level_combo_c.GetCurSel() == 4)
	{
		log->updateLogLevel(LOG_LEVEL_DEBUG);
	}
	else if (log_level_combo_c.GetCurSel() == 5)
	{
		log->updateLogLevel(ENABLE_LOG);
	}
	OnOK();
	// TODO: Add your control notification handler code here
}
