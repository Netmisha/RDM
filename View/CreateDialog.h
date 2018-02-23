#pragma once
#include"resource.h"
#include "afxwin.h"
#include"dll\Table.h"
#include<map>
// CreateDialog dialog

class CreateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CreateDlg)

public:
	CreateDlg(std::map<int,Table*>& db,CWnd* pParent = NULL);   // standard constructor
	virtual ~CreateDlg();

// Dialog Data
	enum { IDD = IDD_CreateDialog };
	BOOL OnInitDialog();
	void Create();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	std::map<int, Table*> database;
	DECLARE_MESSAGE_MAP()
public:
	CEdit create_edit_name_c;
	CEdit create_edit_colt_e;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
};
