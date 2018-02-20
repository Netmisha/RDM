#pragma once
#include"resource.h"
#include "afxwin.h"
#include "afxcmn.h"
#include<map>
#include"dll\Table.h"
// ShowDialog dialog

class ShowDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ShowDialog)

public:
	ShowDialog(std::map<int, Table*>db, CWnd* pParent = NULL);   // standard constructor
	virtual ~ShowDialog();
	BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox show_combo_c;
	CListCtrl show_list_c;
	afx_msg void OnBnClickedButton1();
	std::map <int, Table*> database;
};
