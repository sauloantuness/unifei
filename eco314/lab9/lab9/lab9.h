
// lab9.h : main header file for the lab9 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Clab9App:
// See lab9.cpp for the implementation of this class
//

class Clab9App : public CWinAppEx
{
public:
	Clab9App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab9App theApp;
