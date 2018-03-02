// SelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelectDlg.h"
#include "afxdialogex.h"
#include<algorithm>
#include<map>

// SelectDlg dialog

IMPLEMENT_DYNAMIC(SelectDlg, CDialogEx)

SelectDlg::SelectDlg(Table* tb, std::map<int, Table*>& db, CWnd* pParent /*=NULL*/)
	: CDialogEx(SelectDlg::IDD, pParent)
{
	table = tb;
	database = db;
}

SelectDlg::~SelectDlg()
{
}

BOOL SelectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	std::string temp;
	for (int i = 0; i < table->GetCName().size(); i++)
	{
		temp = table->GetCName()[i];
		std::wstring wname(temp.begin(), temp.end());
		select_combo_name_c.AddString(wname.c_str());
		select_combo_filter_c.AddString(wname.c_str());
	}
	select_names_c.SetWindowTextW(_T("Select "));
	select_filters_c.SetWindowTextW(_T("Where "));
	return TRUE;
}
void SelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, select_combo_name_c);
	DDX_Control(pDX, IDC_COMBO3, select_combo_filter_c);
	DDX_Control(pDX, IDC_EDIT11, select_names_c);
	DDX_Control(pDX, IDC_EDIT9, select_filters_c);
	DDX_Control(pDX, IDC_EDIT3, select_filter_value_c);
	DDX_Control(pDX, IDC_LIST2, select_list_c);
}


BEGIN_MESSAGE_MAP(SelectDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &SelectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &SelectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &SelectDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// SelectDlg message handlers


void SelectDlg::OnBnClickedButton2()
{
	CString cselect;
	select_names_c.GetWindowTextW(cselect);
	CT2CA selectconvert(cselect);
	std::string select(selectconvert);

	CString cname;
	select_combo_name_c.GetWindowTextW(cname);
	CT2CA nameconvert(cname);
	std::string name(nameconvert);
	if (name.empty() || select.empty())
		MessageBox(_T("Provide full input"), _T("Empty field"), NULL);
	else
	{
		if (!strstr(select.c_str(),name.c_str()))
		{
			select = select + " " + name;
			std::wstring wselect(select.begin(), select.end());
			select_names_c.SetWindowTextW(wselect.c_str());
		}
	}
	// TODO: Add your control notification handler code here
}


void SelectDlg::OnBnClickedButton3()
{
	CString cselect;
	select_filters_c.GetWindowTextW(cselect);
	CT2CA selectconvert(cselect);
	std::string select(selectconvert);

	CString cname;
	select_combo_filter_c.GetWindowTextW(cname);
	CT2CA nameconvert(cname);
	std::string name(nameconvert);
	CString cval;
	select_filter_value_c.GetWindowTextW(cval);
	CT2CA valconvert(cval);
	std::string val(valconvert);
	if (val.empty()||name.empty())
		MessageBox(_T("Provide full input"), _T("Empty field"), NULL);
	else
	{
		select = select + " " + name + " = " + val;

		std::wstring wselect(select.begin(), select.end());
		select_filters_c.SetWindowTextW(wselect.c_str());
	}
	// TODO: Add your control notification handler code here
}


void SelectDlg::OnBnClickedButton4()
{
	select_list_c.DeleteAllItems();
	while (true)
	{
		if (select_list_c.DeleteColumn(0) == false)
			break;
	}
	wchar_t wbuff[1024];
	select_names_c.GetWindowTextW(wbuff, 1024);
	std::wstring wtemp(wbuff);
	std::string transform(wtemp.begin(), wtemp.end());
	std::vector<std::wstring> wnames;
	std::string buff;
	std::string output = "";
	std::stringstream ss(transform);
	std::vector<std::string> names;
	while (ss >> buff)
		names.push_back(buff);
	for (int i = 1; i < names.size(); i++)
	{
		std::wstring temp(names[i].begin(), names[i].end());
		wnames.push_back(temp);
	}
	wchar_t wbuff2[1024];
	select_filters_c.GetWindowTextW(wbuff2, 1024);
	std::wstring wtemp2(wbuff2);
	std::string transform2(wtemp2.begin(), wtemp2.end());
	std::vector<std::wstring> wnames2;
	std::string buff2;
	std::string output2 = "";
	std::stringstream ss2(transform2);
	std::vector<std::string> finds;
	while (ss2 >> buff2)
		finds.push_back(buff2);
	for (int i = 1; i < finds.size(); i++)
	{
		std::wstring temp(finds[i].begin(), finds[i].end());
		wnames2.push_back(temp);
	}
	std::vector<std::string> columns;
	for (int i = 1; i < names.size(); i++)
	{
		bool check = false;
		for (int j = 0; j < columns.size(); j++)
		{
			if (names[i] == columns[j])
				check = true;
		}
		if (!check)
			columns.push_back(names[i]);
	}
	Table *selected = new Table(*table);
	int count = 0;
	int colsize = selected->GetCName().size();
	for (int i = 0; i < colsize; i++)
	{
		bool check = false;
		for (int j = 0; j < columns.size(); j++)
		{
			if (selected->GetCName()[i-count] == columns[j])
				check = true;
		}
		if (!check)
		{
			selected->DeleteColumn(i + 1 - count);
			count++;
		}
	}
	std::map<std::string, std::string> filters;
	for (int i = 1; i < finds.size() ; i++)
	{
		std::string first;
		std::string second;
		if (i == 1)
		{
			first = finds[i];
			second = finds[i + 2];
			filters.insert(std::pair<std::string, std::string>(first, second));
			i += 3;
		}
		if (i % 3 == 2)
		{
			first = finds[i-1];
			if ((i + 2) % 3 == 1)
			{
				second = finds[i + 1];
				filters.insert(std::pair<std::string, std::string>(first, second));
			}
		}
	}
	for (int i = 0; i < wnames.size(); i++)
		select_list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
	select_list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
	

	int index = 0;
	for (int i = 0; i < table->Size(); i++)
	{
		bool unique = true;
		int check = 1;
		for (int k = 0; k < table->GetCName().size(); k++)
		{
			bool colcheck = false;
			for (auto p = filters.begin(); p != filters.end(); p++)
			{

				if (table->GetCName()[k] == p->first)
				{
					colcheck = true;
					std::string temp;
					if (table->GetCType()[k] == 'i')
					{
						int *val = static_cast<int*>(table->GetRecord(i + 1)->record[k]->Getv());
						temp = std::to_string(*val);
					}
					else if (table->GetCType()[k] == 'd')
					{
						double *val = static_cast<double*>(table->GetRecord(i + 1)->record[k]->Getv());
						temp = std::to_string(*val);
					}
					else if (table->GetCType()[k] == 's')
					{
						std::string *val = static_cast<std::string*>(table->GetRecord(i + 1)->record[k]->Getv());
						temp = *val;
					}
					if (temp == p->second)
					{
						//break;
					}
					else
						check = check * 0;

				}
				if (check == 0)
					break;
			}
			if (check == 1 && colcheck&&unique)
			{
				std::string id = std::to_string(selected->GetRecord(i + 1)->GetId());
				std::wstring wid(id.begin(), id.end());

				int indexprev = index;
				select_list_c.InsertItem(indexprev, 0);
				select_list_c.SetItemText(index, 0, wid.c_str());
				for (int j = 0; j < selected->GetCName().size(); j++)
				{
					std::string temp;
					if (selected->GetCType()[j] == 'i')
					{
						int *val = static_cast<int*>(selected->GetRecord(i + 1)->record[j]->Getv());
						temp = std::to_string(*val);
					}
					else if (selected->GetCType()[j] == 'd')
					{
						double *val = static_cast<double*>(selected->GetRecord(i + 1)->record[j]->Getv());
						temp = std::to_string(*val);
					}
					else if (selected->GetCType()[j] == 's')
					{
						std::string *val = static_cast<std::string*>(selected->GetRecord(i + 1)->record[j]->Getv());
						temp = *val;
					}
					std::wstring wtemp(temp.begin(), temp.end());

					select_list_c.SetItemText(indexprev, j + 1, wtemp.c_str());

					index++;
				}
				index = indexprev + 1;
				unique = false;
			}
		}
	}
	// TODO: Add your control notification handler code here
}
