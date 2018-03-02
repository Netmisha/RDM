#pragma once
#include"resource.h"
#include"dll\Table.h"
#include<map>
#include "afxwin.h"
#include "afxcmn.h"
#include"EasySize.h"
// SelectDlg dialog

class SelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectDlg)
	DECLARE_EASYSIZE
public:
	SelectDlg(Table* tb, std::map<int, Table*>& db,CWnd* pParent = NULL);   // standard constructor
	virtual ~SelectDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG5 };
	BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	Table* table;
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
	afx_msg void OnBnClickedButton6();
	CStatic select_static_c;
};
