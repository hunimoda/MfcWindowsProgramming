
// Practice_2A.h : main header file for the Practice_2A application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPractice2AApp:
// See Practice_2A.cpp for the implementation of this class
//

class CPractice2AApp : public CWinApp
{
public:
	CPractice2AApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPractice2AApp theApp;
