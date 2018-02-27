#pragma once
#include"resource.h"
#include "afxwin.h"
#include "afxcmn.h"
#include"EasySize.h"
#include<map>
#include"dll\Table.h"
// ShowDialog dialog

class ShowDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ShowDialog)
	DECLARE_EASYSIZE
public:
	ShowDialog(std::map<int, Table*>&db, CWnd* pParent = NULL);   // standard constructor
	virtual ~ShowDialog();
	BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	DECLARE_MESSAGE_MAP()
public:
	CComboBox show_combo_c;
	CListCtrl show_list_c;
	afx_msg void OnBnClickedButton1();

	std::map <int, Table*> database;

	afx_msg void OnBnClickedButton2();
};
