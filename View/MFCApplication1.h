
// MFCApplication1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include"dll\Table.h"
#include"dll\Logger.h"
#include"dll\XML.h"
#include<map>


// CMFCApplication1App:
// See MFCApplication1.cpp for the implementation of this class
//

class CMFCApplication1App : public CWinApp
{
public:
	CMFCApplication1App();
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};
void Fill(std::map<int, Table*>& mapa);
extern CMFCApplication1App theApp;