// LogInsertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LogInsertDlg.h"
#include "afxdialogex.h"
#include"dll\Logger.h"
#include"dll\Table.h"
#include<locale>
#include<codecvt>

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
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wide = converter.from_bytes(type);
	log_type_combo_c.AddString(wide.c_str());
	type = "TRACE";
	wide = converter.from_bytes(type);
	log_type_combo_c.AddString(wide.c_str());
	type = "TRACE";
	wide = converter.from_bytes(type);
	log_type_combo_c.AddString(wide.c_str());
	type = "DEBUG";
	wide = converter.from_bytes(type);
	log_type_combo_c.AddString(wide.c_str());
	type = "ERROR";
	wide = converter.from_bytes(type);
	log_type_combo_c.AddString(wide.c_str());
	type = "ALWAYS";
	wide = converter.from_bytes(type);
	log_type_combo_c.AddString(wide.c_str());
	type = "ALARM"; wide = converter.from_bytes(type);
	log_type_combo_c.AddString(wide.c_str());
	type = "BUFFER";
	wide = converter.from_bytes(type);
	log_type_combo_c.AddString(wide.c_str());
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
