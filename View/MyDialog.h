#pragma once
#include "resource.h"
#include "afxwin.h"

// CMyDialog dialog

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMyDialog();
	BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_DIALOG1 };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit edit;
	afx_msg void OnBnClickedOk();
};
