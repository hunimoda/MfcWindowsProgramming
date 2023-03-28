
// Practice_2B.h : main header file for the Practice_2B application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPractice2BApp:
// See Practice_2B.cpp for the implementation of this class
//

class CPractice2BApp : public CWinApp
{
public:
	CPractice2BApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPractice2BApp theApp;
