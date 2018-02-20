// ShowDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ShowDialog.h"
#include "afxdialogex.h"
#include"MFCApplication1Dlg.h"
#include<string>

// ShowDialog dialog

IMPLEMENT_DYNAMIC(ShowDialog, CDialogEx)

ShowDialog::ShowDialog(std::map<int, Table*>db,CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowDialog::IDD, pParent)
{
	database = db;
}

ShowDialog::~ShowDialog()
{
}

void ShowDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, show_combo_c);
	DDX_Control(pDX, IDC_LIST1, show_list_c);
}

BOOL ShowDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	std::string temp;
	for (auto p = database.begin(); p != database.end(); p++)
	{
		temp = p->second->GetName();
		std::wstring wname(temp.begin(), temp.end());
		show_combo_c.AddString(wname.c_str()); 
	}

	return true;
}

BEGIN_MESSAGE_MAP(ShowDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ShowDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// ShowDialog message handlers


void ShowDialog::OnBnClickedButton1()
{
	show_list_c.DeleteAllItems();
	while (true)
	{
		if (show_list_c.DeleteColumn(0) == false)
			break;
	}
	CString item;
	show_combo_c.GetWindowTextW(item);
	Table *tb;
	bool check = false;
	for (auto p = database.begin(); p != database.end(); p++)
	{
		if (p->second->GetName() == item)
		{
			tb = p->second;
			check = true;
		}
	}
	if (!check)
	{
		MessageBox(_T("There is no table with such name"), _T("No mathc"), NULL);
	}
	else
	{
		std::vector<std::wstring> wnames;
		std::string temp;
		for (unsigned int i = 0; i < tb->GetCName().size(); i++)
		{
			temp = tb->GetCName()[i];
			std::wstring wtemp(temp.begin(), temp.end());
			wnames.push_back(wtemp);
		}
		for (unsigned int i = 0; i < tb->GetCName().size(); i++)
		{
			show_list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
		}
		for (unsigned int i = 0; i < tb->Size(); i++)
		{
			show_list_c.InsertItem(i, 0);
			for (unsigned int j = 0; j < tb->GetCName().size(); j++)
			{
				std::string ptrval;
				void* pval = tb->GetRecord(i + 1)->record[j]->Getv();
				if (tb->GetCType()[j] == 's')
				{
					std::string *ptr = static_cast<std::string*>(pval);
					ptrval = *ptr;
				}
				else if (tb->GetCType()[j] == 'i')
				{
					int *ptr = static_cast<int*>(pval);
					ptrval = std::to_string(*ptr);
				}
				else if (tb->GetCType()[j] == 'd')
				{
					double *ptr = static_cast<double*>(pval);
					ptrval = std::to_string(*ptr);
				}
				std::string val = ptrval;
				std::wstring wtemp(val.begin(), val.end());
				show_list_c.SetItemText(i, j, wtemp.c_str());
			}
		}
	}
	// TODO: Add your control notification handler code here}
}
