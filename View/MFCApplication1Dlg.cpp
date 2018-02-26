
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include"EasySize.h"
#include"CreateDialog.h"
#include"EditDialog.h"
#include<Windows.h>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
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

static int worktableid = 0;
static bool tablecheck = false;
static int _ID = GetLastID() + 1;
static int xmlTableID = 1;
static int _TID;
Table *tb;

CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, m_Edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDV_MaxChars(pDX, m_Edit, 100);
	DDX_Control(pDX, IDC_BUTTON2, m_EditC);
	DDX_Control(pDX, IDC_EDIT1, m_Edit2);
	DDX_Control(pDX, IDC_LIST1, list_c);
	DDX_Control(pDX, IDC_EDIT2, status_c);
	DDX_Control(pDX, IDC_COMBO1, showt_combo_c);
	DDX_Control(pDX, IDC_EDIT4, find_c);
	DDX_Control(pDX, IDC_BUTTON1, find_first_radio_c);
}



BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_COMMAND(ID_HELP_COMMANDS, &CMFCApplication1Dlg::OnHelpCommands)
	ON_COMMAND(ID_FILE_NEWXML, &CMFCApplication1Dlg::OnFileNewxml)
	ON_COMMAND(ID_FILE_SAVE32775, &CMFCApplication1Dlg::OnFileSave32775)
	ON_COMMAND(ID_FILE_SHOW, &CMFCApplication1Dlg::OnFileShow)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication1Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication1Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication1Dlg::OnBnClickedRadio2)
END_MESSAGE_MAP()

BEGIN_EASYSIZE_MAP(CMFCApplication1Dlg)
	EASYSIZE(IDC_EDIT1, ES_BORDER, ES_BORDER, ES_BORDER, ES_KEEPSIZE, 0)
	EASYSIZE(IDC_LIST1, ES_BORDER, ES_BORDER, ES_BORDER, ES_BORDER, 0)
	EASYSIZE(IDC_EDIT2, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, ES_BORDER, 0)
	EASYSIZE(IDC_STATIC, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, ES_BORDER, 0)
END_EASYSIZE_MAP

// CMFCApplication1Dlg message handlers


void CMFCApplication1Dlg::GetDB(std::map<int, Table*>& ddatabase)
{
	database = ddatabase;
}

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	log = NULL;
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

	std::string temp;
	for (auto p = database.begin(); p != database.end(); p++)
	{
		temp = p->second->GetName();
		std::wstring wname(temp.begin(), temp.end());
		showt_combo_c.AddString(wname.c_str());
	}
	showt_combo_c.SetCurSel(0);
	INIT_EASYSIZE;
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

void CMFCApplication1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	UPDATE_EASYSIZE;
}

void CMFCApplication1Dlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialog::OnSizing(fwSide, pRect);
	EASYSIZE_MINSIZE(400, 400, fwSide, pRect);
}
void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


bool SizeCheck(std::vector<std::string>& vec, int size)
{
	if (vec.size() < size)
		return true;
	else
		return false;
}

void CMFCApplication1Dlg::OnBnClickedButton2()
{
	log = Logger::getInstance();
	log->updateLogLevel(LOG_LEVEL_INFO);
	std::string tname = "temp_table";
	//Table *tb;
	if (worktableid == 0)
		tb = new Table(tname);
	else
		tb = database[worktableid];

	wchar_t wbuff[1024];
	m_Edit2.GetWindowTextW(wbuff, 1024);
	std::wstring wtemp(wbuff);
	std::string transform(wtemp.begin(), wtemp.end());
	std::vector<std::wstring> wnames;
	std::string buff;
	std::string output = "";
	std::stringstream ss(transform);
	std::vector<std::string> inputs;
	while (ss >> buff)
		inputs.push_back(buff);
	if (inputs.empty())
	{
		MessageBox(_T("Please provide input"), _T("Empty input"), NULL);
	}
	else
	{
		if (inputs[0] == "create_xml")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			CreateXML();
			m_Edit2.SetWindowTextW(_T(""));
			status_c.SetWindowTextW(_T("XML created"));
		}
		else if (inputs[0] == "build_t")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (SizeCheck(inputs, 2))
			{
				MessageBox(_T("Please provide correct command"), _T("Wrong input"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
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
				if (!check)
				{
					MessageBox(_T("Wrong ID, or XML is empty"), _T("Table does not exist"), NULL);
					status_c.SetWindowTextW(_T("Wrong input"));
				}
				else
				{
					tablecheck = true;
					int x = std::stoi(inputs[1]);
					tb = database[x];
					worktableid = x;
					xmlTableID = x;
					std::string temp;

					for (unsigned int i = 0; i < tb->GetCName().size(); i++)
					{
						temp = tb->GetCName()[i];
						std::wstring wtemp(temp.begin(), temp.end());
						wnames.push_back(wtemp);
					}
					for (unsigned int i = 0; i < tb->GetCName().size(); i++)
					{
						list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
					}
					list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
					for (unsigned int i = 0; i < tb->Size(); i++)
					{
						list_c.InsertItem(i, 0);
						std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
						std::wstring wid(id.begin(), id.end());
						list_c.SetItemText(i, 0, wid.c_str());

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
							std::string val = ptrval;
							std::wstring wtemp(val.begin(), val.end());
							list_c.SetItemText(i, j+1, wtemp.c_str());
						}
					}
					_TID = tb->GetID();
					status_c.SetWindowTextW(_T("Table built"));
				}
				m_Edit2.SetWindowTextW(_T(""));
			}
		}
		else if (inputs[0] == "create_t"&&inputs[1] == "-i")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (SizeCheck(inputs, 5))
			{
				MessageBox(_T("Please provide correct command"), _T("Wrong input"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				tablecheck = true;
				tb = new Table(inputs[2]);
				std::vector<char> coltypes;
				std::vector<std::string> colnames;
				for (unsigned int i = 3; i < inputs.size(); i++)
				{
					if (i % 2 == 0)
					{
						colnames.push_back(inputs[i]);
						std::wstring temp(inputs[i].begin(), inputs[i].end());
						list_c.InsertColumn(i, temp.c_str(), LVCFMT_LEFT, 90);
					}
					else
					{
						if (inputs[i] == "Integer" || inputs[i] == "integer")
							coltypes.push_back('i');
						else if (inputs[i] == "Double" || inputs[i] == "double")
							coltypes.push_back('d');
						else if (inputs[i] == "String" || inputs[i] == "string")
							coltypes.push_back('s');
					}
				}
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
				tb->ChangeID(_ID);
				tb->Create(colnames, coltypes);
				worktableid = _ID;
				xmlTableID = tb->GetID();
				database.insert(std::pair<int, Table*>(ID++, tb));
				_TID = tb->GetID();
				m_Edit2.SetWindowTextW(_T(""));
				status_c.SetWindowTextW(_T("Table created"));
			}
		}
		else if (inputs[0] == "show")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("No table"));
			}
			else
			{
				if (!SizeCheck(inputs,2) && inputs[1] == "-t")
				{

					std::string temp;

					for (unsigned int i = 0; i < tb->GetCName().size(); i++)
					{
						temp = tb->GetCName()[i];
						std::wstring wtemp(temp.begin(), temp.end());
						wnames.push_back(wtemp);
					}
					for (unsigned int i = 0; i < tb->GetCName().size(); i++)
					{
						list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
					}
					list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
					for (unsigned int i = 0; i < tb->Size(); i++)
					{
						list_c.InsertItem(i, 0);
						std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
						std::wstring wid(id.begin(), id.end());
						list_c.SetItemText(i, 0, wid.c_str());
						for (unsigned int j = 0; j < database[_TID]->GetCName().size(); j++)
						{
							std::string ptrval;
							void* pval = database[_TID]->GetRecord(i + 1)->record[j]->Getv();
							if (database[_TID]->GetCType()[j] == 's')
							{
								std::string *ptr = static_cast<std::string*>(pval);
								ptrval = *ptr;
							}
							else if (database[_TID]->GetCType()[j] == 'i')
							{
								int *ptr = static_cast<int*>(pval);
								ptrval = std::to_string(*ptr);
							}
							else if (database[_TID]->GetCType()[j] == 'd')
							{
								double *ptr = static_cast<double*>(pval);
								ptrval = std::to_string(*ptr);
							}
							std::string val = ptrval;
							std::wstring wtemp(val.begin(), val.end());
							list_c.SetItemText(i, j+1, wtemp.c_str());
						}
					}
				}
				else
				{
					MessageBox(_T("Wrong input or probably you lost something"), _T("Wrong input"), NULL);
					status_c.SetWindowTextW(_T("Wrong input"));
				}
			}
		}
		else if (inputs[0] == "log")
		{
			m_Edit2.SetWindowTextW(_T(""));
			std::string logtemp;
			for (int i = 2; i < inputs.size(); i++)
			{
				logtemp += inputs[i];
				logtemp += " ";
			}
			if (inputs[1] == "error")
			{
				LOG_ERROR(logtemp);
			}
			else if (inputs[1] == "alarm")
			{
				LOG_ALARM(logtemp);
			}
			else if (inputs[1] == "always")
			{
				LOG_ALWAYS(logtemp);
			}
			else if (inputs[1] == "info")
			{
				LOG_INFO(logtemp);
			}
			else if (inputs[1] == "buffer")
			{
				LOG_BUFFER(logtemp);
			}
			else if (inputs[1] == "trace")
			{
				LOG_TRACE(logtemp);
			}
			else if (inputs[1] == "debug")
			{
				LOG_DEBUG(logtemp);
			}
			status_c.SetWindowTextW(_T("User log inserted"));
		}
		else if (inputs[0] == "upgrade_log_level")
		{
			m_Edit2.SetWindowTextW(_T(""));
			if (inputs[1] == "disable")
			{
				LOG_ALARM("LOG_LEVEL changed to DISABLE");
				log->updateLogLevel(DISABLE_LOG);
			}
			else if (inputs[1] == "level_info")
			{
				LOG_ALARM("LOG_LEVEL changed to INFO");
				log->updateLogLevel(LOG_LEVEL_INFO);
			}
			else if (inputs[1] == "level_buffer")
			{
				LOG_ALARM("LOG_LEVEL changed to BUFFER");
				log->updateLogLevel(LOG_LEVEL_BUFFER);
			}
			else if (inputs[1] == "level_trace")
			{
				LOG_ALARM("LOG_LEVEL changed to TRACE");
				log->updateLogLevel(LOG_LEVEL_TRACE);
			}
			else if (inputs[1] == "level_debug")
			{
				LOG_ALARM("LOG_LEVEL changed to DEBUG");
				log->updateLogLevel(LOG_LEVEL_DEBUG);
			}
			else if (inputs[1] == "enable")
			{
				LOG_ALARM("LOG_LEVEL changed to ENABLE");
				log->updateLogLevel(ENABLE_LOG);
			}
			status_c.SetWindowTextW(_T("Log level updated"));
		}
		else if (inputs[0] == "update_xml")
		{
			int i = 0;
			for (auto p = database.begin(); p != database.end(); p++)
			{
				i = p->first;
				AddData(*database[i]);
				AddStructure(*database[i]);
				GColector();
			}
			m_Edit2.SetWindowTextW(_T(""));
			status_c.SetWindowTextW(_T("XML updated"));
		}
		else if (inputs[0] == "delete_t")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (SizeCheck(inputs, 2))
			{
				MessageBox(_T("Please provide correct command"), _T("Wrong input"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				bool check = false;
				if (database.count(std::stoi(inputs[1])) == 1)
					check = true;
				if (!check)
				{
					MessageBox(_T("Wrong ID, or XML is empty"), _T("Table does not exist"), NULL);
					status_c.SetWindowTextW(_T("Wrong input"));
				}
				else
				{
					database.erase(std::stoi(inputs[1]));
					tablecheck = false;
					worktableid = 0;
				}
				m_Edit2.SetWindowTextW(_T(""));
				status_c.SetWindowTextW(_T("Table deleted"));
			}
		}
		else if (inputs[0] == "addrec")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			m_Edit2.SetWindowTextW(_T(""));
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				int i = 0;
				if (inputs.size() < tb->GetCName().size() + 1)
				while (inputs.size()  < tb->GetCName().size() + 1)
				{
					if (tb->GetCType()[inputs.size() - 1] == 'i')
						inputs.push_back("0");
					else if (tb->GetCType()[inputs.size() - 1] == 'd')
						inputs.push_back("0.0");
					else if (tb->GetCType()[inputs.size() - 1] == 's')
						inputs.push_back("_");
				}
				else if ((inputs.size() - 1)>tb->GetCName().size())
				while ((inputs.size() - 1) > tb->GetCName().size())
				{
					inputs.erase(inputs.begin() + inputs.size() - 1);
				}
				std::vector<std::string> values;
				for (int j = 1; j < inputs.size(); j++)
				{
					values.push_back(inputs[j]);
				}
				i++;
				while (i < inputs.size() - 1)
				{
					if (tb->GetCType()[i - 1] == 'i'&& TypeFinder(inputs[i]) != 'i')
						values[i] = "0";
					else if (tb->GetCType()[i - 1] == 'd' && (TypeFinder(inputs[i]) != 'd'&& TypeFinder(inputs[i]) != 'i'))
						values[i] = "0";
					else if (tb->GetCType()[i - 1] == 's' && TypeFinder(inputs[i]) != 's')
						values[i] = "_";
					i++;
				}
				tb->AddRecord(values);
				std::string temp;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					temp = tb->GetCName()[i];
					std::wstring wtemp(temp.begin(), temp.end());
					wnames.push_back(wtemp);
				}
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
				}
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
				for (unsigned int i = 0; i < tb->Size(); i++)
				{
					list_c.InsertItem(i, 0);
					std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
					std::wstring wid(id.begin(), id.end());
					list_c.SetItemText(i, 0, wid.c_str());
					for (unsigned int j = 0; j < tb->GetCName().size(); j++)
					{
						std::string ptrval;
						void* pval = tb->GetRecord(i + 1)->record[j]->Getv();
						if (tb->GetCType()[j] == 's')
						{
							std::string *ptr = static_cast<std::string*>(pval);
							ptrval = *ptr;
						}
						else if (tb->GetCType()[j] == 'i')
						{
							int *ptr = static_cast<int*>(pval);
							ptrval = std::to_string(*ptr);
						}
						else if (tb->GetCType()[j] == 'd')
						{
							double *ptr = static_cast<double*>(pval);
							ptrval = std::to_string(*ptr);
						}
						std::string val = ptrval;
						std::wstring wtemp(val.begin(), val.end());
						list_c.SetItemText(i, j+1, wtemp.c_str());
					}
				}
				status_c.SetWindowTextW(_T("New record added"));
			}
		}
		else if (inputs[0] == "addcol")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			m_Edit2.SetWindowTextW(_T(""));
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				std::string type;
				if (inputs[1] == "integer")
				{
					type = "integer";
					tb->AddColumn(type, inputs[2]);
				}
				else if (inputs[1] == "double")
				{
					type = "double";
					tb->AddColumn(type, inputs[2]);
				}
				else if (inputs[1] == "string")
				{
					type = "string";
					tb->AddColumn(type, inputs[2]);
				}
				std::string temp;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					temp = tb->GetCName()[i];
					std::wstring wtemp(temp.begin(), temp.end());
					wnames.push_back(wtemp);
				}
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
				}
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
				for (unsigned int i = 0; i < tb->Size(); i++)
				{
					list_c.InsertItem(i, 0);
					std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
					std::wstring wid(id.begin(), id.end());
					list_c.SetItemText(i, 0, wid.c_str());
					for (unsigned int j = 0; j < tb->GetCName().size(); j++)
					{
						std::string ptrval;
						void* pval = tb->GetRecord(i + 1)->record[j]->Getv();
						if (tb->GetCType()[j] == 's')
						{
							std::string *ptr = static_cast<std::string*>(pval);
							ptrval = *ptr;
						}
						else if (tb->GetCType()[j] == 'i')
						{
							int *ptr = static_cast<int*>(pval);
							ptrval = std::to_string(*ptr);
						}
						else if (tb->GetCType()[j] == 'd')
						{
							double *ptr = static_cast<double*>(pval);
							ptrval = std::to_string(*ptr);
						}
						std::string val = ptrval;
						std::wstring wtemp(val.begin(), val.end());
						list_c.SetItemText(i, j+1, wtemp.c_str());
					}
				}
				status_c.SetWindowTextW(_T("New column added"));
			}
		}
		else if (inputs[0] == "delrec")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				std::string::size_type sz;
				tb->DeleteRecord(std::stoi(inputs[1], &sz));
				std::string temp;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					temp = tb->GetCName()[i];
					std::wstring wtemp(temp.begin(), temp.end());
					wnames.push_back(wtemp);
				}
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
				}
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
				for (unsigned int i = 0; i < tb->Size(); i++)
				{
					list_c.InsertItem(i, 0);
					std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
					std::wstring wid(id.begin(), id.end());
					list_c.SetItemText(i, 0, wid.c_str());
					for (unsigned int j = 0; j < tb->GetCName().size(); j++)
					{
						std::string ptrval;
						void* pval = tb->GetRecord(i + 1)->record[j]->Getv();
						if (tb->GetCType()[j] == 's')
						{
							std::string *ptr = static_cast<std::string*>(pval);
							ptrval = *ptr;
						}
						else if (tb->GetCType()[j] == 'i')
						{
							int *ptr = static_cast<int*>(pval);
							ptrval = std::to_string(*ptr);
						}
						else if (tb->GetCType()[j] == 'd')
						{
							double *ptr = static_cast<double*>(pval);
							ptrval = std::to_string(*ptr);
						}
						std::string val = ptrval;
						std::wstring wtemp(val.begin(), val.end());
						list_c.SetItemText(i, j+1, wtemp.c_str());
					}
				}
				status_c.SetWindowTextW(_T("Record deleted"));
			}
		}
		else if (inputs[0] == "find")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				if (tb->FindRecord(inputs[1]) == NULL)
				{
					MessageBox(_T("No match"), _T("Not found"), NULL);
					status_c.SetWindowTextW(_T("Wrong input"));
				}
				else
				{
					std::string temp;
					for (unsigned int i = 0; i < tb->GetCName().size(); i++)
					{
						temp = tb->GetCName()[i];
						std::wstring wtemp(temp.begin(), temp.end());
						wnames.push_back(wtemp);
					}
					for (int i = 0; i < tb->GetCName().size(); i++)
						list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
					list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
					list_c.InsertItem(0, 0);
					for (int i = 0; i < tb->GetCName().size(); i++)
					{
						std::string ptrval;

						void* pval = tb->FindRecord(inputs[1])->record[i]->Getv();
						if (pval == NULL)
						{
							MessageBox(_T("No match"), _T("Not found"), NULL);
							status_c.SetWindowTextW(_T("Wrong input"));
						}
						else
						{
							if (tb->GetCType()[i] == 's')
							{
								std::string *ptr = static_cast<std::string*>(pval);
								if (ptr == NULL)
								{
									MessageBox(_T("No match"), _T("Not found"), NULL);
									status_c.SetWindowTextW(_T("Wrong input"));
								}
								else
								{
									ptrval = *ptr;
									status_c.SetWindowTextW(_T("Record found"));
								}
							}
							else if (tb->GetCType()[i] == 'i')
							{
								int *ptr = static_cast<int*>(pval);
								if (ptr == NULL)
								{
									MessageBox(_T("No match"), _T("Not found"), NULL);
									status_c.SetWindowTextW(_T("Wrong input"));
								}
								else
								{
									ptrval = std::to_string(*ptr);
									status_c.SetWindowTextW(_T("Record found"));
								}
							}
							else if (tb->GetCType()[i] == 'd')
							{
								double *ptr = static_cast<double*>(pval);
								if (ptr == NULL)
								{
									MessageBox(_T("No match"), _T("Not found"), NULL);
									status_c.SetWindowTextW(_T("Wrong input"));
								}
								else
								{
									ptrval = std::to_string(*ptr);
									status_c.SetWindowTextW(_T("Record found"));
								}
							}
							std::string val = ptrval;
							std::wstring wtemp(val.begin(), val.end());
							std::string id = std::to_string(tb->FindRecord(inputs[1])->GetId());
							std::wstring wid(id.begin(), id.end());
							list_c.SetItemText(i, 0, wid.c_str());

							list_c.SetItemText(0, i+1, wtemp.c_str());
						}
					}
				}
			}
		}
		else if (inputs[0] == "select")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				std::vector<std::string> columns;
				for (int i = 1; i < inputs.size(); i++)
				{
					columns.push_back(inputs[i]);
				}

				std::vector<int> position;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					for (unsigned int j = 0; j < columns.size(); j++)
					{
						if (tb->GetCName()[i] == columns[j])
						{
							position.push_back(i);
						}
					}
				}
				int i = 0;
				for (auto p = position.begin(); p != position.end(); p++)
				{
					std::wstring name(tb->GetCName()[position[i]].begin(), tb->GetCName()[position[i]].end());
					list_c.InsertColumn(i, name.c_str(), LVCFMT_LEFT, 90);
					i++;
				}
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
				std::vector<std::string> values;
				for (unsigned int i = 0; i < tb->Size(); i++)
				{
					for (unsigned int j = 0; j < tb->GetRecord(i + 1)->record.size(); j++)
					{
						list_c.InsertItem(i, 0);
						std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
						std::wstring wid(id.begin(), id.end());
						list_c.SetItemText(i, 0, wid.c_str());
						for (auto p = position.begin(); p != position.end(); p++)
						{
							std::string temp;
							if (tb->GetCType()[position[j]] == 'i')
							{
								int* ptr = (int*)tb->GetRecord(i + 1)->record[*p]->Getv();
								int test = *ptr;
								temp = std::to_string(test);
							}
							else if (tb->GetCType()[position[j]] == 'd')
							{
								double* ptr = (double*)tb->GetRecord(i + 1)->record[*p]->Getv();
								double test = *ptr;
								temp = std::to_string(test);
							}
							else if (tb->GetCType()[position[j]] == 's')
							{
								std::string* ptr = (std::string*)tb->GetRecord(i + 1)->record[*p]->Getv();
								std::string test = *ptr;
								temp = test;
							}
							std::wstring val(temp.begin(), temp.end());
							list_c.SetItemText(i, j+1, val.c_str());
							j++;
						}
						break;
					}
				}
				status_c.SetWindowTextW(_T("Selected columns"));
			}
		}
		else if (inputs[0] == "findall")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (tb->FindRecord(inputs[1]) == NULL)
			{
				MessageBox(_T("No match"), _T("Not found"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				if (!tablecheck)
				{
					MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
					status_c.SetWindowTextW(_T("Wrong input"));
				}
				std::string temp;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					temp = tb->GetCName()[i];
					std::wstring wtemp(temp.begin(), temp.end());
					wnames.push_back(wtemp);
				}
				for (int i = 0; i < tb->GetCName().size(); i++)
					list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);

				for (int j = 0; j < tb->Size(); j++)
				{
					if (tb->GetRecord(j + 1)->Find(inputs[1]))
					{
						int count = 0;
						list_c.InsertItem(count, 0);
						std::string id = std::to_string(tb->GetRecord(j + 1)->GetId());
						std::wstring wid(id.begin(), id.end());
						list_c.SetItemText(count, 0, wid.c_str());

						for (int i = 0; i < tb->GetCName().size(); i++)
						{
							std::string ptrval;
							void* pval;
							pval = tb->GetRecord(j + 1)->record[i]->Getv();
							if (pval == NULL)
							{
								MessageBox(_T("No match"), _T("Not found"), NULL);
								status_c.SetWindowTextW(_T("Wrong input"));
								break;
							}
							else
							{
								if (tb->GetCType()[i] == 's')
								{
									std::string *ptr = static_cast<std::string*>(pval);
									if (ptr == NULL)
									{
										MessageBox(_T("No match"), _T("Not found"), NULL);
										status_c.SetWindowTextW(_T("Wrong input"));
										break;
									}
									else
									{
										status_c.SetWindowTextW(_T("Records found"));
										ptrval = *ptr;
									}
								}
								else if (tb->GetCType()[i] == 'i')
								{
									int *ptr = static_cast<int*>(pval);
									if (ptr == NULL)
									{
										MessageBox(_T("No match"), _T("Not found"), NULL);
										status_c.SetWindowTextW(_T("Wrong input"));
										break;
									}
									else
									{
										status_c.SetWindowTextW(_T("Records found"));
										ptrval = std::to_string(*ptr);
									}
								}
								else if (tb->GetCType()[i] == 'd')
								{
									double *ptr = static_cast<double*>(pval);
									if (ptr == NULL)
									{
										MessageBox(_T("No match"), _T("Not found"), NULL);
										status_c.SetWindowTextW(_T("Wrong input"));
										break;
									}
									else
									{
										status_c.SetWindowTextW(_T("Records found"));
										ptrval = std::to_string(*ptr);
									}
								}
								std::string val = ptrval;
								std::wstring wtemp(val.begin(), val.end());

								list_c.SetItemText(count, i + 1, wtemp.c_str());
							}
						}
					}
				}
			}
		}
		else if (inputs[0] == "set")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				if (inputs[1] == "-s")
				{
					if (std::stoi(inputs[2]) > tb->Size())
					{
						MessageBox(_T("No mathces found"), _T("Not found"), NULL);
						status_c.SetWindowTextW(_T("Wrong input"));
					}
					else
					{
						tb->Set(std::stoi(inputs[2]), std::stoi(inputs[3]), inputs[4]);
						status_c.SetWindowTextW(_T("New value set"));
					}
				}
				else if (inputs[1] == "-c")
				{
					tb->Set(std::stoi(inputs[2]), inputs[3], inputs[4]);
					status_c.SetWindowTextW(_T("New value set"));
				}
				else if (inputs[1] == "-r")
				{
					if (std::stoi(inputs[2]) > tb->Size())
					{
						MessageBox(_T("Record ID out of range"), _T("Out of range"), NULL);
						status_c.SetWindowTextW(_T("Wrong input"));
					}
					else
					{
						for (unsigned int i = 3; i < inputs.size(); i++)
						{
							if (i>tb->GetCName().size() + 2)
								continue;
							else
								tb->Set(std::stoi(inputs[2]), i - 2, inputs[i]);
						}
					}
					status_c.SetWindowTextW(_T("New record set"));
				}
				std::string temp;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					temp = tb->GetCName()[i];
					std::wstring wtemp(temp.begin(), temp.end());
					wnames.push_back(wtemp);
				}
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
				}
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
				for (unsigned int i = 0; i < tb->Size(); i++)
				{
					list_c.InsertItem(i, 0);
					std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
					std::wstring wid(id.begin(), id.end());
					list_c.SetItemText(i, 0, wid.c_str());
					for (unsigned int j = 0; j < tb->GetCName().size(); j++)
					{
						std::string ptrval;
						void* pval = tb->GetRecord(i + 1)->record[j]->Getv();
						if (tb->GetCType()[j] == 's')
						{
							std::string *ptr = static_cast<std::string*>(pval);
							ptrval = *ptr;
						}
						else if (tb->GetCType()[j] == 'i')
						{
							int *ptr = static_cast<int*>(pval);
							ptrval = std::to_string(*ptr);
						}
						else if (tb->GetCType()[j] == 'd')
						{
							double *ptr = static_cast<double*>(pval);
							ptrval = std::to_string(*ptr);
						}
						std::string val = ptrval;
						std::wstring wtemp(val.begin(), val.end());
						list_c.SetItemText(i, j+1, wtemp.c_str());
					}
				}
			}
		}
		else if (inputs[0] == "inherit")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				tb->AddTable(*database[std::stoi(inputs[1])]);
				status_c.SetWindowTextW(_T("Table inherited"));
				std::string temp;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					temp = tb->GetCName()[i];
					std::wstring wtemp(temp.begin(), temp.end());
					wnames.push_back(wtemp);
				}
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
				}
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
				for (unsigned int i = 0; i < tb->Size(); i++)
				{
					list_c.InsertItem(i, 0);
					std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
					std::wstring wid(id.begin(), id.end());
					list_c.SetItemText(i, 0, wid.c_str());
					for (unsigned int j = 0; j < tb->GetCName().size(); j++)
					{
						std::string ptrval;
						void* pval = tb->GetRecord(i + 1)->record[j]->Getv();
						if (tb->GetCType()[j] == 's')
						{
							std::string *ptr = static_cast<std::string*>(pval);
							ptrval = *ptr;
						}
						else if (tb->GetCType()[j] == 'i')
						{
							int *ptr = static_cast<int*>(pval);
							ptrval = std::to_string(*ptr);
						}
						else if (tb->GetCType()[j] == 'd')
						{
							double *ptr = static_cast<double*>(pval);
							ptrval = std::to_string(*ptr);
						}
						std::string val = ptrval;
						std::wstring wtemp(val.begin(), val.end());
						list_c.SetItemText(i, j+1, wtemp.c_str());
					}
				}
			}
		}
		else if (inputs[0] == "delcol")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				if (inputs[1] == "-id")
				{
					if (std::stoi(inputs[2]) > tb->GetCName().size())
					{
						MessageBox(_T("There is no column with such id"), _T("Column does not exist"), NULL);
						status_c.SetWindowTextW(_T("Wrong input"));
					}
					else
					{
						tb->DeleteColumn(std::stoi(inputs[2]));
						status_c.SetWindowTextW(_T("Column deleted"));
					}
				}
				else if (inputs[1] == "-s")
				{
					bool check = false;
					for (int i = 0; i < tb->GetCName().size(); i++)
					{
						if (inputs[2] == tb->GetCName()[i])
						{
							check = true;
							break;
						}
					}
					tb->DeleteColumn(inputs[2]);
					status_c.SetWindowTextW(_T("Column deleted"));
				}

				std::string temp;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					temp = tb->GetCName()[i];
					std::wstring wtemp(temp.begin(), temp.end());
					wnames.push_back(wtemp);
				}
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
				}
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
				for (unsigned int i = 0; i < tb->Size(); i++)
				{
					list_c.InsertItem(i, 0);
					std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
					std::wstring wid(id.begin(), id.end());
					list_c.SetItemText(i, 0, wid.c_str());
					for (unsigned int j = 0; j < tb->GetCName().size(); j++)
					{
						std::string ptrval;
						void* pval = tb->GetRecord(i + 1)->record[j]->Getv();
						if (tb->GetCType()[j] == 's')
						{
							std::string *ptr = static_cast<std::string*>(pval);
							ptrval = *ptr;
						}
						else if (tb->GetCType()[j] == 'i')
						{
							int *ptr = static_cast<int*>(pval);
							ptrval = std::to_string(*ptr);
						}
						else if (tb->GetCType()[j] == 'd')
						{
							double *ptr = static_cast<double*>(pval);
							ptrval = std::to_string(*ptr);
						}
						std::string val = ptrval;
						std::wstring wtemp(val.begin(), val.end());
						list_c.SetItemText(i, j+1, wtemp.c_str());
					}

				}
			}
		}
		else if (inputs[0] == "clear")
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				tb->Clear();
				status_c.SetWindowTextW(_T("Table cleared"));
			}
		}
		else if (inputs[0] == "get")
		{
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else if (inputs[1] == "-id")
			{
				std::string ID;
				ID = std::to_string(tb->GetID());
				std::wstring wID(ID.begin(), ID.end());
				MessageBox(wID.c_str(), _T("Table ID"), NULL);
				status_c.SetWindowTextW(_T("Got ID"));
			}
			else if (inputs[1] == "-name")
			{
				std::string name = tb->GetName();
				std::wstring wname(name.begin(), name.end());
				MessageBox(wname.c_str(), _T("Table name"), NULL);
				status_c.SetWindowTextW(_T("Got name"));
			}
			else if (inputs[1] == "-size")
			{
				std::string size;
				size = std::to_string(tb->Size());
				std::wstring wsize(size.begin(), size.end());
				MessageBox(wsize.c_str(), _T("Table size"), NULL);
				status_c.SetWindowTextW(_T("Got size"));
			}
		}
		else
		{
			MessageBox(_T("There is no such command, use help"), _T("Wrong input"), NULL);
			status_c.SetWindowTextW(_T("Wrong input"));
		}
	}
}



void CMFCApplication1Dlg::OnHelpCommands()
{
	CMyDialog diag;
	diag.DoModal();
	// TODO: Add your command handler code here
}


void CMFCApplication1Dlg::OnFileNewxml()
{
	CreateXML();
	status_c.SetWindowTextW(_T("New XML"));
	// TODO: Add your command handler code here
}


void CMFCApplication1Dlg::OnFileSave32775()
{
	for each (std::pair<int,Table*> var in database)
	{
		AddData(*var.second);
		AddStructure(*var.second);
	}
	status_c.SetWindowTextW(_T("Saved"));
	// TODO: Add your command handler code here
}


void CMFCApplication1Dlg::OnFileShow()
{
	ShowDialog diag(database);
	diag.DoModal();
	// TODO: Add your command handler code here
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	::CreateDlg d(database);
	d.DoModal();
	Fill(database);
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	tablecheck = true;
	CString cname;
	showt_combo_c.GetWindowTextW(cname);
	CT2CA convertedname(cname);
	std::string name(convertedname);
	for (auto p = database.begin(); p != database.end(); p++)
	{
		if (p->second->GetName() == name)
		{
			worktableid = p->second->GetID();
			_TID = worktableid;
			break;
		}
	}
	list_c.DeleteAllItems();
	while (true)
	{
		if (list_c.DeleteColumn(0) == false)
			break;
	}
	CString item;
	showt_combo_c.GetWindowTextW(item);
	bool check = false;
	for (auto p = database.begin(); p != database.end(); p++)
	{
		if (p->second->GetName() == item)
		{
			tb = p->second;
			check = true;
		}
	}
	if (!check)
	{
		MessageBox(_T("There is no table with such name"), _T("No mathc"), NULL);
	}
	else
	{
		std::vector<std::wstring> wnames;
		std::string temp;
		for (unsigned int i = 0; i < tb->GetCName().size(); i++)
		{
			temp = tb->GetCName()[i];
			std::wstring wtemp(temp.begin(), temp.end());
			wnames.push_back(wtemp);
		}
		
		for (unsigned int i = 0; i < tb->GetCName().size(); i++)
		{
			list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
		}
		list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
		for (unsigned int i = 0; i < tb->Size(); i++)
		{
			list_c.InsertItem(i, 0);

			std::string id = std::to_string(tb->GetRecord(i + 1)->GetId());
			std::wstring wid(id.begin(), id.end());
			list_c.SetItemText(i, 0, wid.c_str());

			for (unsigned int j = 0; j < tb->GetCName().size(); j++)
			{
				std::string ptrval;
				void* pval = tb->GetRecord(i + 1)->record[j]->Getv();
				if (tb->GetCType()[j] == 's')
				{
					std::string *ptr = static_cast<std::string*>(pval);
					ptrval = *ptr;
				}
				else if (tb->GetCType()[j] == 'i')
				{
					int *ptr = static_cast<int*>(pval);
					ptrval = std::to_string(*ptr);
				}
				else if (tb->GetCType()[j] == 'd')
				{
					double *ptr = static_cast<double*>(pval);
					ptrval = std::to_string(*ptr);
				}
				std::string val = ptrval;
				std::wstring wtemp(val.begin(), val.end());

				list_c.SetItemText(i, j + 1, wtemp.c_str());
			}

		}
	}
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	if (worktableid != 0)
	{
		EditDialog diag(tb);
		diag.DoModal();
	}
	else
	{
		MessageBox(_T("There is no current table"), _T("Nothing to work with"), NULL);
	}
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	if (worktableid != 0)
	{
		CString ctext;
		find_c.GetWindowTextW(ctext);
		CT2CA textconvert(ctext);
		std::string text(textconvert);
		std::vector<std::wstring> wnames;
		if (find_first)
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				if (tb->FindRecord(text) == NULL)
				{
					MessageBox(_T("No match"), _T("Not found"), NULL);
					status_c.SetWindowTextW(_T("Wrong input"));
				}
				else
				{
					std::string temp;
					for (unsigned int i = 0; i < tb->GetCName().size(); i++)
					{
						temp = tb->GetCName()[i];
						std::wstring wtemp(temp.begin(), temp.end());
						wnames.push_back(wtemp);
					}
					for (int i = 0; i < tb->GetCName().size(); i++)
						list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
					list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);
					list_c.InsertItem(0, 0);
					for (int i = 0; i < tb->GetCName().size(); i++)
					{
						std::string ptrval;

						void* pval = tb->FindRecord(text)->record[i]->Getv();
						if (pval == NULL)
						{
							MessageBox(_T("No match"), _T("Not found"), NULL);
							status_c.SetWindowTextW(_T("Wrong input"));
						}
						else
						{
							if (tb->GetCType()[i] == 's')
							{
								std::string *ptr = static_cast<std::string*>(pval);
								if (ptr == NULL)
								{
									MessageBox(_T("No match"), _T("Not found"), NULL);
									status_c.SetWindowTextW(_T("Wrong input"));
								}
								else
								{
									ptrval = *ptr;
									status_c.SetWindowTextW(_T("Record found"));
								}
							}
							else if (tb->GetCType()[i] == 'i')
							{
								int *ptr = static_cast<int*>(pval);
								if (ptr == NULL)
								{
									MessageBox(_T("No match"), _T("Not found"), NULL);
									status_c.SetWindowTextW(_T("Wrong input"));
								}
								else
								{
									ptrval = std::to_string(*ptr);
									status_c.SetWindowTextW(_T("Record found"));
								}
							}
							else if (tb->GetCType()[i] == 'd')
							{
								double *ptr = static_cast<double*>(pval);
								if (ptr == NULL)
								{
									MessageBox(_T("No match"), _T("Not found"), NULL);
									status_c.SetWindowTextW(_T("Wrong input"));
								}
								else
								{
									ptrval = std::to_string(*ptr);
									status_c.SetWindowTextW(_T("Record found"));
								}
							}
							std::string val = ptrval;
							std::wstring wtemp(val.begin(), val.end());
							std::string id = std::to_string(tb->FindRecord(text)->GetId());
							std::wstring wid(id.begin(), id.end());
							list_c.SetItemText(i, 0, wid.c_str());

							list_c.SetItemText(0, i + 1, wtemp.c_str());
						}
					}
				}
			}
		}
		else if (find_all)
		{
			list_c.DeleteAllItems();
			while (true)
			{
				if (list_c.DeleteColumn(0) == false)
					break;
			}
			if (tb->FindRecord(text) == NULL)
			{
				MessageBox(_T("No match"), _T("Not found"), NULL);
				status_c.SetWindowTextW(_T("Wrong input"));
			}
			else
			{
				if (!tablecheck)
				{
					MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
					status_c.SetWindowTextW(_T("Wrong input"));
				}
				std::string temp;
				for (unsigned int i = 0; i < tb->GetCName().size(); i++)
				{
					temp = tb->GetCName()[i];
					std::wstring wtemp(temp.begin(), temp.end());
					wnames.push_back(wtemp);
				}
				for (int i = 0; i < tb->GetCName().size(); i++)
					list_c.InsertColumn(i, wnames[i].c_str(), LVCFMT_LEFT, 90);
				list_c.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);

				for (int j = 0; j < tb->Size(); j++)
				{
					if (tb->GetRecord(j + 1)->Find(text))
					{
						int count = 0;
						list_c.InsertItem(count, 0);
						std::string id = std::to_string(tb->GetRecord(j + 1)->GetId());
						std::wstring wid(id.begin(), id.end());
						list_c.SetItemText(count, 0, wid.c_str());

						for (int i = 0; i < tb->GetCName().size(); i++)
						{
							std::string ptrval;
							void* pval;
							pval = tb->GetRecord(j + 1)->record[i]->Getv();
							if (pval == NULL)
							{
								MessageBox(_T("No match"), _T("Not found"), NULL);
								status_c.SetWindowTextW(_T("Wrong input"));
								break;
							}
							else
							{
								if (tb->GetCType()[i] == 's')
								{
									std::string *ptr = static_cast<std::string*>(pval);
									if (ptr == NULL)
									{
										MessageBox(_T("No match"), _T("Not found"), NULL);
										status_c.SetWindowTextW(_T("Wrong input"));
										break;
									}
									else
									{
										status_c.SetWindowTextW(_T("Records found"));
										ptrval = *ptr;
									}
								}
								else if (tb->GetCType()[i] == 'i')
								{
									int *ptr = static_cast<int*>(pval);
									if (ptr == NULL)
									{
										MessageBox(_T("No match"), _T("Not found"), NULL);
										status_c.SetWindowTextW(_T("Wrong input"));
										break;
									}
									else
									{
										status_c.SetWindowTextW(_T("Records found"));
										ptrval = std::to_string(*ptr);
									}
								}
								else if (tb->GetCType()[i] == 'd')
								{
									double *ptr = static_cast<double*>(pval);
									if (ptr == NULL)
									{
										MessageBox(_T("No match"), _T("Not found"), NULL);
										status_c.SetWindowTextW(_T("Wrong input"));
										break;
									}
									else
									{
										status_c.SetWindowTextW(_T("Records found"));
										ptrval = std::to_string(*ptr);
									}
								}
								std::string val = ptrval;
								std::wstring wtemp(val.begin(), val.end());

								list_c.SetItemText(count, i + 1, wtemp.c_str());
							}
						}
					}
				}
			}
		}
	}
	else
	{
		MessageBox(_T("There is no current table"), _T("Nothing to work with"), NULL);
	}
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedRadio1()
{
	find_first = true;
	find_all == false;
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedRadio2()
{
	find_first = false;
	find_all == true;
	// TODO: Add your control notification handler code here
}
