
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

static int worktableid = 0;
static bool tablecheck = false;
static int _ID = GetLastID() + 1;
static int xmlTableID = 1;
static int _TID;

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


bool SizeCheck(std::vector<std::string>& vec, int size)
{
	if (vec.size() < size)
		return true;
	else
		return false;
}

void CMFCApplication1Dlg::OnBnClickedButton2()
{
	
	
	while (true)
	{
		if (list_c.DeleteColumn(0) == false)
			break;
	}
	std::string tname = "temp_table";
	Table *tb;
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
	if (inputs[0] == "help")
	{
		MessageBox(_T("Soon here would be help"), _T("Help"), NULL);
		m_Edit2.SetWindowTextW(_T(""));
	}
	else if (inputs[0] == "create_xml")
	{
		CreateXML();
		m_Edit2.SetWindowTextW(_T(""));
	}
	else if (inputs[0] == "build_t")
	{
		if (SizeCheck(inputs, 2))
			MessageBox(_T("Please provide correct command"), _T("Wrong input"), NULL);
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
		}
		else
		{
			tablecheck = true;
			int x = stoi(inputs[1]);
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
			for (unsigned int i = 0; i < tb->Size(); i++)
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
					std::string val = ptrval;
					std::wstring wtemp(val.begin(), val.end());
					list_c.SetItemText(i, j, wtemp.c_str());
				}
			}
			_TID = tb->GetID();
			//table built
		}
		m_Edit2.SetWindowTextW(_T(""));
	}
	else if (inputs[0] == "create_t"&&inputs[1]=="-i")
	{
		if (SizeCheck(inputs,5))
			MessageBox(_T("Please provide correct command"), _T("Wrong input"), NULL);
		tablecheck = true;
		tb = new Table(inputs[2]);
		std::vector<char> coltypes;
		std::vector<std::string> colnames;
		for (unsigned int i = 3; i < inputs.size(); i++)
		{
			if (i % 2 == 0)
			{
				colnames.push_back(inputs[i]);
				std::wstring temp(inputs[i].begin(),inputs[i].end());
				list_c.InsertColumn(i,temp.c_str(), LVCFMT_LEFT, 90);
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
		tb->ChangeID(_ID);
		tb->Create(colnames, coltypes);
		worktableid = _ID;
		//out << "table created \n";
		xmlTableID = tb->GetID();
		database.insert(std::pair<int, Table*>(ID++, tb));
		_TID = tb->GetID();
		m_Edit2.SetWindowTextW(_T(""));
	}
	else if (inputs[0] == "logger")
	{
		m_Edit2.SetWindowTextW(_T(""));
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
		//out << "XML updated \n";
	}
	else if (inputs[0] == "delete_t")
	{
		if (SizeCheck(inputs, 2))
			MessageBox(_T("Please provide correct command"), _T("Wrong input"), NULL);
		bool check = false;
		if (database.count(std::stoi(inputs[1])) == 1)
			check = true;
		if (!check)
		{
			MessageBox(_T("Wrong ID, or XML is empty"), _T("Table does not exist"), NULL);
		}
		else
		{
			//out << "Table " << database[std::stoi(inputs[1])]->GetName() << " deleted \n";
			database.erase(std::stoi(inputs[1]));
			tablecheck = false;
			worktableid = 0;
		}
		m_Edit2.SetWindowTextW(_T(""));
	}
	else if (inputs[0] == "addrec")
	{
		m_Edit2.SetWindowTextW(_T(""));
		
		if (tablecheck)
			MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
		int i = 0;
		if (inputs.size() < tb->GetCName().size()+1)
		while (inputs.size()  < tb->GetCName().size()+1)
		{
			if (tb->GetCType()[inputs.size()-1] == 'i')
				inputs.push_back("0");
			else if (tb->GetCType()[inputs.size()-1] == 'd')
				inputs.push_back("0");
			else if (tb->GetCType()[inputs.size()-1] == 's')
				inputs.push_back("_");
		}
		else if ((inputs.size() - 1)>tb->GetCName().size())
		while ((inputs.size() - 1)>tb->GetCName().size())
		{
			inputs.erase(inputs.begin() + inputs.size() - 1);
		}
		std::vector<std::string> values;
		for (int j = 1; j < inputs.size(); j++)
		{
			values.push_back(inputs[j]);
		}
		i++;
		while (i < inputs.size()-1)
		{
			if (tb->GetCType()[i-1] == 'i'&& TypeFinder(inputs[i]) != 'i')
				values[i] = "0";
			else if (tb->GetCType()[i - 1] == 'd' && (TypeFinder(inputs[i]) != 'd'&& TypeFinder(inputs[i]) != 'i'))
				values[i] = "0";
			else if (tb->GetCType()[i - 1] == 's' && TypeFinder(inputs[i]) != 's')
				values[i] = "_";
			i++;
		}
		tb->AddRecord(values);
		
		//out new record added

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
		for (unsigned int i = 0; i < tb->Size(); i++)
		{
			list_c.InsertItem(i, 0);
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
				list_c.SetItemText(i, j, wtemp.c_str());
			}
		}
	}
	else if (inputs[0] == "addcol")
	{
		m_Edit2.SetWindowTextW(_T(""));
		
		if (tablecheck)
		{
			MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
		}
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
		//out << "new column added\n";
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
		for (unsigned int i = 0; i < tb->Size(); i++)
		{
			list_c.InsertItem(i, 0);
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
				list_c.SetItemText(i, j, wtemp.c_str());
			}
		}
	}
	else if (inputs[0] == "delrec")
	{
		if (tablecheck)
		{
			MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
		}
		std::string::size_type sz;
		tb->DeleteRecord(std::stoi(inputs[1], &sz));
		//out << "record deleted\n";
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
		for (unsigned int i = 0; i < tb->Size(); i++)
		{
			list_c.InsertItem(i, 0);
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
				list_c.SetItemText(i, j, wtemp.c_str());
			}
		}
	}
	else if (inputs[0] == "find")
	{
		if (!tablecheck)
		{
			MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
		}
		else
		{
			if (tb->FindRecord(inputs[1]) == NULL)
			{
				MessageBox(_T("No match"), _T("Not found"), NULL);
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
				list_c.InsertItem(0, 0);
				for (int i = 0; i < tb->GetCName().size(); i++)
				{
					std::string ptrval;

					void* pval = tb->FindRecord(inputs[1])->record[i]->Getv();
					if (pval == NULL)
					{
						MessageBox(_T("No match"), _T("Not found"), NULL);
					}
					else
					{
						if (tb->GetCType()[i] == 's')
						{
							std::string *ptr = static_cast<std::string*>(pval);
							if (ptr == NULL)
								MessageBox(_T("No match"), _T("Not found"), NULL);
							else
								ptrval = *ptr;
						}
						else if (tb->GetCType()[i] == 'i')
						{
							int *ptr = static_cast<int*>(pval);
							if (ptr == NULL)
								MessageBox(_T("No match"), _T("Not found"), NULL);
							else
								ptrval = std::to_string(*ptr);
						}
						else if (tb->GetCType()[i] == 'd')
						{
							double *ptr = static_cast<double*>(pval); if (ptr == NULL)
								MessageBox(_T("No match"), _T("Not found"), NULL);
							else
								ptrval = std::to_string(*ptr);
						}
						std::string val = ptrval;
						std::wstring wtemp(val.begin(), val.end());
						list_c.SetItemText(0, i, wtemp.c_str());
					}

				}
			}
		}
	}
	else if (inputs[0] == "select") //does not work now
	{
		if (tablecheck)
		{
			MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
		}
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
			std::wstring name(tb->GetCName()[position[*p]].begin(), tb->GetCName()[position[*p]].end());
			list_c.InsertColumn(i, name.c_str(), LVCFMT_LEFT, 90);
			i++;
		}
		std::vector<std::string> values;
		for (unsigned int i = 0; i < tb->Size(); i++)
		{
			for (unsigned int j = 0; j < tb->GetRecord(i+1)->record.size(); j++)
			{
				for (auto p = position.begin(); p != position.end(); p++)
				{

				}
				break;
			}

		}
	}
	else if (inputs[0] == "findall")
	{
		if (tb->FindRecord(inputs[1]) == NULL)
		{
			MessageBox(_T("No match"), _T("Not found"), NULL);
		}
		else
		{
			if (!tablecheck)
			{
				MessageBox(_T("There is no current table, please create or build one"), _T("Table does not exist"), NULL);
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
			for (int j = 0; j < tb->Size(); j++)
			{
				list_c.InsertItem(j, 0);
				for (int i = 0; i < tb->GetCName().size(); i++)
				{
					std::string ptrval;
					void* pval;
					if (tb->GetRecord(j + 1)->Find(inputs[1]))
					{
						pval=tb->GetRecord(j + 1)->record[i]->Getv();
					}
					else break;
					if (pval == NULL)
					{
						MessageBox(_T("No match"), _T("Not found"), NULL);
					}
					else
					{
						
						if (tb->GetCType()[i] == 's')
						{
							std::string *ptr = static_cast<std::string*>(pval);
							if (ptr == NULL)
								MessageBox(_T("No match"), _T("Not found"), NULL);
							else
							{
								ptrval = *ptr;
							}
						}
						else if (tb->GetCType()[i] == 'i')
						{
							int *ptr = static_cast<int*>(pval);
							if (ptr == NULL)
								MessageBox(_T("No match"), _T("Not found"), NULL);
							else
							{
								ptrval = std::to_string(*ptr);
							}
						}
						else if (tb->GetCType()[i] == 'd')
						{
							double *ptr = static_cast<double*>(pval);
							if (ptr == NULL)
								MessageBox(_T("No match"), _T("Not found"), NULL);
							else
							{
								ptrval = std::to_string(*ptr);
							}
						}
						std::string val = ptrval;
						std::wstring wtemp(val.begin(), val.end());
						list_c.SetItemText(j, i, wtemp.c_str());
					}
				}
			}
		}
	}
}