// MyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include<string>
// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDialog::IDD, pParent)
{
}

CMyDialog::~CMyDialog()
{
}

BOOL CMyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: Add extra initialization here
	std::string temp;
	temp = "To work with table:\r\n";
	temp += "\t create_t -i 'table name' 'column type' 'column name'... - create new table\r\n";
	temp += "\t build_t ID - build table from XML\r\n";
	temp += "\t create_xml - create new XML files\r\n";
	temp += "\t clear - clear the content of current table\r\n";
	temp += "\t addrec 'value' ... - add new record to current table \r\n";
	temp += "\t addcol 'column type' 'column name' - add new colemn to current table\r\n";
	temp += "\t delrec ID - delete record from current table\r\n";
	temp += "\t delcol ID - delete column from current table\r\n";
	temp += "\t delete_t - delete current table\r\n";
	temp += "\t show -t - show current table content\r\n";
	temp += "\t find -d ID - show record at ID position\r\n";
	temp += "\t find -s 'value' - show first record that contain 'value'\r\n";
	temp += "\t findall -s 'value' - show all recolds that contain 'value'\r\n";
	temp += "\t select 'column name' 'column name'-show choosed columns content\r\n";
	temp += "\t set -s rowindex columnindex 'value' -set cell at 'rowindex' 'columnindex' position to value\r\n";
	temp += "\t set -c rowindex 'column name' 'value' - set cell \r\n";
	temp += "\t set -r 'index' 'value' ... - set record with index position 'value'...\r\n";
	temp += "\t update_xml - update content of XML files\r\n";
	temp += "\t get -id - show id of current table\r\n";
	temp += "\t get -name - show name of current table\r\n";
	temp += "\t get -size - show size of current table\r\n";
	temp += "\t inherit_t ID - update current table with table[ID] structure\r\n";
	temp += "\nto work with logger:\r\n";
	temp += "\t logger - go to logger settings\r\n";
	temp += "\t error type 'message' - insert error type message\r\n";
	temp += "\t alarm type 'message' - insert alarm type message\r\n";
	temp += "\t always type 'message' - insert always type message\r\n";
	temp += "\t info type 'message' - insert info type message\r\n";
	temp += "\t buffer type 'message' - insert buffer type message\r\n";
	temp += "\t trace type 'message' - insert trace type message\r\n";
	temp += "\t debug type 'message' - insert debug typemessage\r\n";
	temp += "\t update_log_level 'level type' - change logging level to 'level type'\r\n";
	temp += "\n\t level types:\r\n";
	temp += "\t\t disable\r\n";
	temp += "\t\t level_info\r\n";
	temp += "\t\t level_buffer\r\n";
	temp += "\t\t level_trace\r\n";
	temp += "\t\t level_debug\r\n";
	temp += "\t\t enable\r\n";
	temp += "\n\t update_log_type 'log type' - change logging type typ 'log type'\r\n";
	temp += "\n\t log levels:\r\n";
	temp += "\t\t file - log into logfile\r\n";
	temp += "\t\t no_log - disable logging\r\n";
	std::wstring wtemp(temp.begin(), temp.end());
	edit.SetWindowText(wtemp.c_str()); // Initialize control values
	edit.ShowWindow(SW_SHOW);      // Show or hide a control, etc.

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyDialog::OnBnClickedOk)
END_MESSAGE_MAP()



// CMyDialog message handlers


void CMyDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
