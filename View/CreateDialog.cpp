// CreateDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CreateDialog.h"
#include "afxdialogex.h"
#include"dll\XML.h"
#include<string>


// CreateDialog dialog

IMPLEMENT_DYNAMIC(CreateDlg, CDialogEx)

CreateDlg::CreateDlg(std::map<int, Table*>& db, CEdit* statusc, CComboBox* comboc, CWnd* pParent /*=NULL*/)
: CDialogEx(CreateDlg::IDD, pParent)
{
	database = db;
	main_status = statusc;
	main_combo = comboc;
}

CreateDlg::~CreateDlg()
{
}

BOOL CreateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE;
}

void CreateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, create_edit_name_c);
	DDX_Control(pDX, IDC_EDIT2, create_edit_colt_e);
}


BEGIN_MESSAGE_MAP(CreateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CreateDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CreateDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CreateDialog message handlers


void CreateDlg::OnBnClickedButton3()
{
	Create();
	std::string temp;
	main_combo->ResetContent();
	for (auto p = database.begin(); p != database.end(); p++)
	{
		temp = p->second->GetName();
		std::wstring wname(temp.begin(), temp.end());
		main_combo->AddString(wname.c_str());
	}
	main_combo->SetCurSel(0);
	main_status->SetWindowTextW(_T("Table created"));
	OnOK();
	// TODO: Add your control notification handler code here
}
void CreateDlg::Create()
{
	bool check = true;
	CString csname;
	create_edit_name_c.GetWindowTextW(csname);
	CT2CA pszConvertedAnsiString(csname);
	std::string name(pszConvertedAnsiString);
	Table *temp = new Table(name);
	wchar_t wbuff[1024];
	create_edit_colt_e.GetWindowTextW(wbuff, 1024);
	std::wstring wtemp(wbuff);
	std::string transform(wtemp.begin(), wtemp.end());
	std::vector<std::wstring> wnames;
	std::string buff;
	std::string output = "";
	std::stringstream ss(transform);
	std::vector<std::string> inputs;
	while (ss >> buff)
		inputs.push_back(buff);
	if (inputs.size() < 2 || inputs.size() % 2 == 1)
	{
		MessageBox(_T("Provide correct input"), _T("Wrong input"), NULL);
	}
	else
	{
		std::vector<std::string> names;
		std::vector<char> types;
		for (int i = 0; i < inputs.size(); i++)
		{
			if (i % 2 != 0)
			{
				names.push_back(inputs[i]);
			}
			else
			{
				if (inputs[i] == "Integer" || inputs[i] == "integer")
					types.push_back('i');
				else if (inputs[i] == "Double" || inputs[i] == "double")
					types.push_back('d');
				else if (inputs[i] == "String" || inputs[i] == "string")
					types.push_back('s');
				else
				{
					MessageBox(_T("Provide correct column type"), _T("Non-existing type"), NULL);
					check = false;
					break;
				}
			}
		}
		if (check)
		{
			temp->Create(names, types);
			auto p = database.end();
			p--;
			int id = p->second->GetID() + 1;
			temp->ChangeID(id);
			database.insert(std::pair<int,Table*>(id,temp));
			AddData(*temp);
			AddStructure(*temp);
		}
	}
}


void CreateDlg::OnBnClickedButton1()
{
	OnOK();
	// TODO: Add your control notification handler code here
}
