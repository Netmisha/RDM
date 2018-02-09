
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include<Windows.h>
#include<string>
#include<sstream>
#include<vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, m_Edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDV_MaxChars(pDX, m_Edit, 100);
	DDX_Control(pDX, IDC_BUTTON2, m_EditC);
	DDX_Control(pDX, IDC_EDIT1, m_Edit2);
	DDX_Control(pDX, IDC_LIST1, list_c);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

void CMFCApplication1Dlg::GetDB(std::map<int, Table*>& ddatabase)
{
	database = ddatabase;
}

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


std::wstring ToWide(std::string& source)
{
	std::wstring wstr(source.begin(), source.end());
	return wstr;
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	while (true)
	{
		if (list_c.DeleteColumn(0) == false)
			break;
	}
	std::string tname = "temp_table";
	Table *tb = new Table(tname);
	wchar_t wbuff[1024];
	m_Edit2.GetWindowTextW(wbuff,1024);
	std::wstring temp(wbuff);
	std::string transform(temp.begin(), temp.end());

	std::string buff;
	std::string output = "";
	std::stringstream ss(transform);
	std::vector<std::string> inputs;
	while (ss >> buff)
		inputs.push_back(buff);
	if (inputs[0] == "build_t")
	{
		//	if (SizeCheck(inputs, 2, out))
		//		continue;
		bool check = false;
		int *idarr = GetID();
		for (unsigned int i = 1; i < database.size() + 1; i++)
		{
			if (database[idarr[i - 1]]->GetID() == std::stoi(inputs[1]))
			{
				check = true;
				break;
			}
		}
		
		//	if (!check)
		//	{
		//		out << "there is no table with " << inputs[1] << " ID\n";
		//		continue;
		//	}
		//	else
		//	{
		//		tablecheck = true;
		int x = stoi(inputs[1]);
		tb = database[x];
		//		xmlTableID = x;
		//		out << "table built \n";
		//		tb->Show(out);
		std::string temp ;
		std::vector<std::wstring> wnames;
		for (unsigned int i = 0; i < tb->GetCName().size(); i++)
		{
			temp = tb->GetCName()[i];
			//std::wstring wtemp=ToWide(temp);
			std::wstring wtemp(temp.begin(), temp.end());
			wnames.push_back(wtemp);
		}
		for (unsigned int i = 0; i < tb->GetCName().size(); i++)
		{
			list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
		}
		for (unsigned int i = 0; i < database.size(); i++)
		{
			list_c.InsertItem(i, 0);
			for (unsigned int j = 0; j < database[std::stoi(inputs[1])]->GetCName().size(); j++)
			{
				std::string ptrval;
				void* pval = database[std::stoi(inputs[1])]->GetRecord(i + 1)->record[j]->Getv();
				if (database[std::stoi(inputs[1])]->GetCType()[j] == 's')
				{
					std::string *ptr = static_cast<std::string*>(pval);
					ptrval = *ptr;
				}
				else if (database[std::stoi(inputs[1])]->GetCType()[j] == 'i')
				{
					int *ptr = static_cast<int*>(pval);
					ptrval = std::to_string(*ptr);
				}
				else if (database[std::stoi(inputs[1])]->GetCType()[j] == 'd')
				{
					double *ptr = static_cast<double*>(pval);
					ptrval = std::to_string(*ptr);
				}
				
				MessageBoxA(NULL,ptrval.c_str(),0,MB_OK);
				std::string val = ptrval;
				std::wstring wtemp(val.begin(), val.end());
				list_c.SetItemText(i, j, wtemp.c_str());
			}
		}
		TID = tb->GetID();
		//	}

	}
	
	// TODO: Add your control notification handler code here
}
