
// lab10.h : main header file for the lab10 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Clab10App:
// See lab10.cpp for the implementation of this class
//

class Clab10App : public CWinAppEx
{
public:
	Clab10App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab10App theApp;
