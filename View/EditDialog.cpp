// EditDialog.cpp : implementation file
//

#include "stdafx.h"
#include "EditDialog.h"
#include "afxdialogex.h"


// EditDialog dialog

IMPLEMENT_DYNAMIC(EditDialog, CDialogEx)

EditDialog::EditDialog(Table* tb, std::map<int, Table*>& db, CEdit* statusc, CListCtrl* mlist, CWnd* pParent /*=NULL*/)
: CDialogEx(EditDialog::IDD, pParent)
{
	table = tb;
	main_status_c=statusc;
	database = db;
	main_list_c = mlist;
}

BOOL EditDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	std::string type = "string";
	std::wstring wtype(type.begin(), type.end());
	add_col_type_combo_c.AddString(wtype.c_str());
	type = "integer";
	std::wstring wtype2(type.begin(), type.end());
	add_col_type_combo_c.AddString(wtype2.c_str());
	type = "double";
	std::wstring wtype3(type.begin(), type.end());
	add_col_type_combo_c.AddString(wtype3.c_str());
	add_col_type_combo_c.SetCurSel(2);

	std::string temp;
	for (auto p = database.begin(); p != database.end(); p++)
	{
		temp = p->second->GetName();
		std::wstring wname(temp.begin(), temp.end());
		edit_inherit_combo_c.AddString(wname.c_str());
	}
	edit_inherit_combo_c.SetCurSel(0);
	return TRUE;
}

EditDialog::~EditDialog()
{
}

void RePaint(Table* table,CListCtrl* main_list_c)
{
	main_list_c->DeleteAllItems();
	while (true)
	{
		if (main_list_c->DeleteColumn(0) == false)
			break;
	}
	std::vector<std::wstring> wnames;
	std::string temp;
	for (unsigned int i = 0; i < table->GetCName().size(); i++)
	{
		temp = table->GetCName()[i];
		std::wstring wtemp(temp.begin(), temp.end());
		wnames.push_back(wtemp);
	}

	for (unsigned int i = 0; i < table->GetCName().size(); i++)
	{
		main_list_c->InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
	}
	main_list_c->InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
	for (unsigned int i = 0; i < table->Size(); i++)
	{
		main_list_c->InsertItem(i, 0);

		std::string id = std::to_string(table->GetRecord(i + 1)->GetId());
		std::wstring wid(id.begin(), id.end());
		main_list_c->SetItemText(i, 0, wid.c_str());

		for (unsigned int j = 0; j < table->GetCName().size(); j++)
		{
			std::string ptrval;
			void* pval = table->GetRecord(i + 1)->record[j]->Getv();
			if (table->GetCType()[j] == 's')
			{
				std::string *ptr = static_cast<std::string*>(pval);
				ptrval = *ptr;
			}
			else if (table->GetCType()[j] == 'i')
			{
				int *ptr = static_cast<int*>(pval);
				ptrval = std::to_string(*ptr);
			}
			else if (table->GetCType()[j] == 'd')
			{
				double *ptr = static_cast<double*>(pval);
				ptrval = std::to_string(*ptr);
			}
			std::string val = ptrval;
			std::wstring wtemp(val.begin(), val.end());

			main_list_c->SetItemText(i, j + 1, wtemp.c_str());
		}

	}
}
void EditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_addrec_c);
	DDX_Control(pDX, IDC_EDIT3, edit_delrec_c);
	DDX_Control(pDX, IDC_EDIT4, edit_set_row_c);
	DDX_Control(pDX, IDC_EDIT5, edit_set_col_c);
	DDX_Control(pDX, IDC_EDIT6, edit_set_val_c);
	DDX_Control(pDX, IDC_EDIT7, set_rec_id_c);
	DDX_Control(pDX, IDC_EDIT8, set_rec_val_c);
	DDX_Control(pDX, IDC_EDIT10, del_col_id_c);
	DDX_Control(pDX, IDC_COMBO1, add_col_type_combo_c);
	DDX_Control(pDX, IDC_EDIT12, add_col_name_c);
	DDX_Control(pDX, IDC_COMBO2, edit_inherit_combo_c);
}


BEGIN_MESSAGE_MAP(EditDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &EditDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &EditDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &EditDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &EditDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &EditDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &EditDialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &EditDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &EditDialog::OnBnClickedButton7)
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
	if (inputs.empty())
	{
		MessageBox(_T("Provide at least some info"), _T("Empty input"), NULL);
		main_status_c->SetWindowTextW(_T("Record add failed"));
	}
	else
	{
		table->AddRecord(inputs);
		main_status_c->SetWindowTextW(_T("Record added"));
		RePaint(table, main_list_c);
		OnOK();
	}
	// TODO: Add your control notification handler code here
}


void EditDialog::OnBnClickedButton3()
{
	CString cid;
	edit_delrec_c.GetWindowTextW(cid);
	CT2CA pconvert(cid);
	std::string id(pconvert);
	bool check = false;
	for (int i = 0; i < table->Size(); i++)
	{
		if (std::stoi(id) == table->GetRecord(i+1)->GetId())
			check = true;
	}
	if (check)
	{
		table->DeleteRecord(std::stoi(id));
		main_status_c->SetWindowTextW(_T("Record deleted"));
		RePaint(table, main_list_c);
		OnOK();
	}
	else
		MessageBox(_T("There is no record with such ID"), _T("Not found"), NULL);
	// TODO: Add your control notification handler code here
}


void EditDialog::OnBnClickedButton4()
{
	CString crow;
	edit_set_row_c.GetWindowTextW(crow);
	CT2CA rowconvert(crow);
	std::string row(rowconvert);
	if (std::stoi(row) > table->Size() || std::stoi(row) < 1)
		MessageBox(_T("Row index out of range"), _T("Out of range"), NULL);
	else
	{
		CString ccol;
		edit_set_col_c.GetWindowTextW(ccol);
		CT2CA colconvert(ccol);
		std::string col(colconvert);
		CString cval;
		edit_set_val_c.GetWindowTextW(cval);
		CT2CA valconvert(cval);
		std::string val(valconvert);
		if (TypeFinder(col) == 'i')
		{
			if (std::stoi(col) > table->GetCName().size())
				MessageBox(_T("Column index out of range"), _T("Out of range"), NULL);
			else
			{
				table->Set(std::stoi(row), std::stoi(col), val);
				main_status_c->SetWindowTextW(_T("Value set"));
				RePaint(table, main_list_c);
				OnOK();
			}
		}
		else if (TypeFinder(col) == 's')
		{
			bool check = false;
			for (unsigned int i = 0; i < table->GetCName().size(); i++)
			{
				if (col == table->GetCName()[i])
					check = true;
			}
			if (!check)
				MessageBox(_T("There is no column with such name"), _T("No match"), NULL);
			else
			{
				table->Set(std::stoi(row), col, val);
				main_status_c->SetWindowTextW(_T("Value set"));
				RePaint(table, main_list_c);
				OnOK();
			}
		}
	}
	// TODO: Add your control notification handler code here
}


void EditDialog::OnBnClickedButton2()
{
	CString cid;
	set_rec_id_c.GetWindowTextW(cid);
	CT2CA idconvert(cid);
	std::string id(idconvert);
	if (std::stoi(id) < table->Size()+1 && std::stoi(id) >0)
	{
		wchar_t wbuff[1024];
		set_rec_val_c.GetWindowTextW(wbuff, 1024);
		std::wstring wtemp(wbuff);
		std::string transform(wtemp.begin(), wtemp.end());
		std::vector<std::wstring> wnames;
		std::string buff;
		std::string output = "";
		std::stringstream ss(transform);
		std::vector<std::string> inputs;
		while (ss >> buff)
			inputs.push_back(buff);
		for (unsigned int i = 0; i < inputs.size(); i++)
		{
			table->Set(std::stoi(id), i + 1, inputs[i]);
		}
		main_status_c->SetWindowTextW(_T("Record set"));
		RePaint(table, main_list_c);
		OnOK();
	}
	else
		MessageBox(_T("Record index out of range"), _T("Out of range"), NULL);
	// TODO: Add your control notification handler code here
}


void EditDialog::OnBnClickedButton5()
{
	CString cname;
	add_col_name_c.GetWindowTextW(cname);
	CT2CA nameconvert(cname);
	std::string name(nameconvert);
	CString ctype;
	add_col_type_combo_c.GetWindowTextW(ctype);
	CT2CA typeconvert(ctype);
	std::string type(typeconvert);
	table->AddColumn(type,name);
	main_status_c->SetWindowTextW(_T("Column added"));
	RePaint(table, main_list_c);
	OnOK();
	// TODO: Add your control notification handler code here
}


void EditDialog::OnBnClickedButton8()
{
	CString cid_name;
	del_col_id_c.GetWindowTextW(cid_name);
	CT2CA id_nameconvert(cid_name);
	std::string id_name(id_nameconvert);
	if (TypeFinder(id_name) == 'i')
	{
		if (std::stoi(id_name) > 0 && std::stoi(id_name) < table->GetCName().size()+1)
		{
			table->DeleteColumn(std::stoi(id_name));
			main_status_c->SetWindowTextW(_T("Column deleted"));
			RePaint(table, main_list_c);
			OnOK();
		}
		else
			MessageBox(_T("There is no column with such index"), _T("Out of range"), NULL);
	}
	else if (TypeFinder(id_name) == 's')
	{
		bool check = false;
		for (int i = 0; i < table->GetCName().size(); i++)
		{
			if (id_name == table->GetCName()[i])
				check = true;
		}
		if (!check)
			MessageBox(_T("There is no column with such name"), _T("No match"), NULL);
		else
		{
			table->DeleteColumn(id_name);
			main_status_c->SetWindowTextW(_T("Column deleted"));
			RePaint(table, main_list_c);
			OnOK();
		}
	}
	// TODO: Add your control notification handler code here
}


void EditDialog::OnBnClickedButton6()
{
	table->Clear();
	main_status_c->SetWindowTextW(_T("Table cleared"));
	RePaint(table, main_list_c);
	// TODO: Add your control notification handler code here
}


void EditDialog::OnBnClickedButton7()
{
	CString ctablename;
	edit_inherit_combo_c.GetWindowTextW(ctablename);
	CT2CA tableconvert(ctablename);
	std::string tablename(tableconvert);
	for (auto p = database.begin(); p != database.end(); p++)
	{
		if (p->second->GetName() == tablename)
		{
			table->AddTable(*p->second);
			main_status_c->SetWindowTextW(_T("Table inherited"));
			RePaint(table, main_list_c);
			break;
		}
	}
	OnOK();
	// TODO: Add your control notification handler code here
}
