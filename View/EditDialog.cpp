// EditDialog.cpp : implementation file
//

#include "stdafx.h"
#include "EditDialog.h"
#include "afxdialogex.h"


// EditDialog dialog

IMPLEMENT_DYNAMIC(EditDialog, CDialogEx)

EditDialog::EditDialog(Table* tb,CWnd* pParent /*=NULL*/)
	: CDialogEx(EditDialog::IDD, pParent)
{
	table = tb;
}

BOOL EditDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE;
}

EditDialog::~EditDialog()
{
}

void EditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_addrec_c);
	DDX_Control(pDX, IDC_EDIT3, edit_delrec_c);
}


BEGIN_MESSAGE_MAP(EditDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &EditDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &EditDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// EditDialog message handlers


void EditDialog::OnBnClickedButton1()
{
	CString csname;
	edit_addrec_c.GetWindowTextW(csname);
	CT2CA pszConvertedAnsiString(csname);
	std::string name(pszConvertedAnsiString);
	Table *temp = new Table(name);
	wchar_t wbuff[1024];
	edit_addrec_c.GetWindowTextW(wbuff, 1024);
	std::wstring wtemp(wbuff);
	std::string transform(wtemp.begin(), wtemp.end());
	std::vector<std::wstring> wnames;
	std::string buff;
	std::string output = "";
	std::stringstream ss(transform);
	std::vector<std::string> inputs;
	while (ss >> buff)
		inputs.push_back(buff);
	table->AddRecord(inputs);
	// TODO: Add your control notification handler code here
}


void EditDialog::OnBnClickedButton3()
{
	CString cid;
	edit_delrec_c.GetWindowTextW(cid);
	CT2CA pconvert(cid);
	std::string id(pconvert);
	table->DeleteRecord(std::stoi(id));
	OnOK();
	// TODO: Add your control notification handler code here
}
