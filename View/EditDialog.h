#pragma once

#include"resource.h"
#include "afxwin.h"
#include"dll\Table.h"
#include<map>
// EditDialog dialog


class EditDialog : public CDialogEx
{
	DECLARE_DYNAMIC(EditDialog)

public:
	EditDialog(Table* db, std::map<int, Table*>& data, CEdit* statuscCListCtrl, CListCtrl* mlist, CWnd* pParent = NULL);   // standard constructor
	virtual ~EditDialog();
	CEdit* main_status_c;
	CListCtrl* main_list_c;
// Dialog Data
	enum { IDD = IDD_EditDialog };
	BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	Table* table;
	std::map<int, Table*> database;
	DECLARE_MESSAGE_MAP()
public:
	CEdit edit_addrec_c;
	afx_msg void OnBnClickedButton1();
	CEdit edit_delrec_c;
	afx_msg void OnBnClickedButton3();
	CEdit edit_set_row_c;
	CEdit edit_set_col_c;
	CEdit edit_set_val_c;
	afx_msg void OnBnClickedButton4();
	CEdit set_rec_id_c;
	CEdit set_rec_val_c;
	afx_msg void OnBnClickedButton2();
	CEdit del_col_id_c;
	CEdit add_col_c;
	afx_msg void OnBnClickedButton5();
	CComboBox add_col_type_combo_c;
	CEdit add_col_name_c;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	CComboBox edit_inherit_combo_c;
	afx_msg void OnBnClickedButton7();
};
