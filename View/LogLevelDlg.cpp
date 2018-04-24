// LogLevelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LogLevelDlg.h"
#include "afxdialogex.h"
#include<locale>
#include<codecvt>

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
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wide = converter.from_bytes(level);
	log_level_combo_c.AddString(wide.c_str());
	level = "INFO";
	wide = converter.from_bytes(level);
	log_level_combo_c.AddString(wide.c_str());
	level = "BUFFER";
	wide = converter.from_bytes(level);
	log_level_combo_c.AddString(wide.c_str());
	level = "TRACE";
	wide = converter.from_bytes(level);
	log_level_combo_c.AddString(wide.c_str());
	level = "DEBUG";
	wide = converter.from_bytes(level);
	log_level_combo_c.AddString(wide.c_str());
	level = "ENABLE";
	wide = converter.from_bytes(level);
	log_level_combo_c.AddString(wide.c_str());
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
