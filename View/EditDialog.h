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
	EditDialog(Table* db,CWnd* pParent = NULL);   // standard constructor
	virtual ~EditDialog();

// Dialog Data
	enum { IDD = IDD_EditDialog };
	BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	Table* table;
	DECLARE_MESSAGE_MAP()
public:
	CEdit edit_addrec_c;
	afx_msg void OnBnClickedButton1();
	CEdit edit_delrec_c;
	afx_msg void OnBnClickedButton3();
};
