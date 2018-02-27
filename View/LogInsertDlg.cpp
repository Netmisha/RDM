// LogInsertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LogInsertDlg.h"
#include "afxdialogex.h"
#include"dll\Logger.h"
#include"dll\Table.h"

// LogInsertDlg dialog

IMPLEMENT_DYNAMIC(LogInsertDlg, CDialogEx)

LogInsertDlg::LogInsertDlg(Logger *logger,CWnd* pParent /*=NULL*/)
	: CDialogEx(LogInsertDlg::IDD, pParent)
{
	log = logger;
}

LogInsertDlg::~LogInsertDlg()
{
}

BOOL LogInsertDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	std::string type = "INFO";
	std::wstring wtype(type.begin(), type.end());
	log_type_combo_c.AddString(wtype.c_str());
	type = "TRACE";
	std::wstring wtype2(type.begin(), type.end());
	log_type_combo_c.AddString(wtype2.c_str());
	type = "DEBUG";
	std::wstring wtype3(type.begin(), type.end());
	log_type_combo_c.AddString(wtype3.c_str());
	type = "ERROR";
	std::wstring wtype4(type.begin(), type.end());
	log_type_combo_c.AddString(wtype4.c_str());
	type = "ALWAYS";
	std::wstring wtype5(type.begin(), type.end());
	log_type_combo_c.AddString(wtype5.c_str());
	type = "ALARM";
	std::wstring wtype6(type.begin(), type.end());
	log_type_combo_c.AddString(wtype6.c_str());
	type = "BUFFER";
	std::wstring wtype7(type.begin(), type.end());
	log_type_combo_c.AddString(wtype7.c_str());
	log_type_combo_c.SetCurSel(0);
	return TRUE;
}
void LogInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, log_type_combo_c);
	DDX_Control(pDX, IDC_EDIT1, log_text_c);
}


BEGIN_MESSAGE_MAP(LogInsertDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LogInsertDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// LogInsertDlg message handlers


void LogInsertDlg::OnBnClickedButton1()
{
	CString ctext;
	log_text_c.GetWindowTextW(ctext);
	CT2CA textconvert(ctext);
	std::string text(textconvert);
	if (log_type_combo_c.GetCurSel() == 0)
	{
		log_text_c.GetWindowTextW(ctext);
		CT2CA convert(ctext);
		std::string input(convert);
		log->info(input);
	}
	else if(log_type_combo_c.GetCurSel() == 1)
	{
		log_text_c.GetWindowTextW(ctext);
		CT2CA convert(ctext);
		std::string input(convert);
		log->trace(input);
	}
	else if (log_type_combo_c.GetCurSel() == 2)
	{
		log_text_c.GetWindowTextW(ctext);
		CT2CA convert(ctext);
		std::string input(convert);
		log->debug(input);
	}
	else if (log_type_combo_c.GetCurSel() == 3)
	{
		log_text_c.GetWindowTextW(ctext);
		CT2CA convert(ctext);
		std::string input(convert);
		log->error(input);
	}
	else if (log_type_combo_c.GetCurSel() == 4)
	{
		log_text_c.GetWindowTextW(ctext);
		CT2CA convert(ctext);
		std::string input(convert);
		log->always(input);
	}
	else if (log_type_combo_c.GetCurSel() == 5)
	{
		log_text_c.GetWindowTextW(ctext);
		CT2CA convert(ctext);
		std::string input(convert);
		log->alarm(input);
	}
	else if (log_type_combo_c.GetCurSel() == 6)
	{
		log_text_c.GetWindowTextW(ctext);
		CT2CA convert(ctext);
		std::string input(convert);
		log->buffer(input);
	}
	// TODO: Add your control notification handler code here
}
