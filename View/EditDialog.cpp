// EditDialog.cpp : implementation file
//

#include "stdafx.h"
#include "EditDialog.h"
#include "afxdialogex.h"


// EditDialog dialog

IMPLEMENT_DYNAMIC(EditDialog, CDialogEx)

EditDialog::EditDialog(Table* tb, CWnd* pParent /*=NULL*/)
: CDialogEx(EditDialog::IDD, pParent)
{
	table = tb;
}

BOOL EditDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	std::string type = "integer";
	std::wstring wtype(type.begin(), type.end());
	add_col_type_combo_c.AddString(wtype.c_str());
	type = "double";
	std::wstring wtype2(type.begin(), type.end());
	add_col_type_combo_c.AddString(wtype2.c_str());
	type = "string";
	std::wstring wtype3(type.begin(), type.end());
	add_col_type_combo_c.AddString(wtype3.c_str());

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
	DDX_Control(pDX, IDC_EDIT4, edit_set_row_c);
	DDX_Control(pDX, IDC_EDIT5, edit_set_col_c);
	DDX_Control(pDX, IDC_EDIT6, edit_set_val_c);
	DDX_Control(pDX, IDC_EDIT7, set_rec_id_c);
	DDX_Control(pDX, IDC_EDIT8, set_rec_val_c);
	DDX_Control(pDX, IDC_EDIT10, del_col_id_c);
	DDX_Control(pDX, IDC_COMBO1, add_col_type_combo_c);
	DDX_Control(pDX, IDC_EDIT12, add_col_name_c);
}


BEGIN_MESSAGE_MAP(EditDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &EditDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &EditDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &EditDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &EditDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &EditDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &EditDialog::OnBnClickedButton8)
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
	OnOK();
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
	if (std::stoi(id) < table->Size() && std::stoi(id) >0)
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
		if (std::stoi(id_name) > 0 && std::stoi(id_name) < table->GetCName().size())
		{
			table->DeleteColumn(std::stoi(id_name));
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
			OnOK();
		}
	}
	// TODO: Add your control notification handler code here
}
