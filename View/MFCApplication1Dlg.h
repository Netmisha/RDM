
// MFCApplication1Dlg.h : header file
//

#pragma once

#include"dll\Table.h"
#include"dll\Logger.h"
#include"dll\XML.h"
#include"EasySize.h"
#include<map>
#include "afxwin.h"
#include "afxcmn.h"
#include "MyDialog.h"
#include"ShowDialog.h"
#include"CreateDialog.h"


// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
	DECLARE_EASYSIZE
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// standard constructor
	std::map<int, Table*> database;
// Dialog Data
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	DECLARE_MESSAGE_MAP()
public:
	CString m_Edit;
	afx_msg void OnEnChangeEdit1();
	void GetDB(std::map<int, Table*>& ddatabase);
	afx_msg void OnBnClickedButton2();
	CButton m_EditC;
	CEdit m_Edit2;
	CListCtrl list_c;
	CEdit status_c;
	Logger *log;
	afx_msg void OnHelpCommands();
	afx_msg void OnFileNewxml();
	afx_msg void OnFileSave32775();
	afx_msg void OnFileShow();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox showt_combo_c;
	afx_msg void OnBnClickedButton6();
	CEdit find_c;
	afx_msg void OnBnClickedButton8();
	CButton find_first_radio_c;
	bool find_first;
	bool find_all;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
