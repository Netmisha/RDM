#pragma once
#include"resource.h"
#include"dll\Table.h"
#include<map>
#include "afxwin.h"
#include "afxcmn.h"
// SelectDlg dialog

class SelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectDlg)

public:
	SelectDlg(Table tb, std::map<int, Table*>& db,CWnd* pParent = NULL);   // standard constructor
	virtual ~SelectDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG5 };
	BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	Table table;
	std::map<int, Table*> database;
	DECLARE_MESSAGE_MAP()
public:
	CComboBox select_combo_name_c;
	CComboBox select_combo_filter_c;
	CEdit select_names_c;
	CEdit select_filters_c;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CEdit select_filter_value_c;
	afx_msg void OnBnClickedButton4();
	CListCtrl select_list_c;
};
