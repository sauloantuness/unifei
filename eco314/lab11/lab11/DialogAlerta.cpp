// DialogAlerta.cpp : implementation file
//

#include "stdafx.h"
#include "lab11.h"
#include "DialogAlerta.h"
#include "afxdialogex.h"


// CDialogAlerta dialog

IMPLEMENT_DYNAMIC(CDialogAlerta, CDialogEx)

CDialogAlerta::CDialogAlerta(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogAlerta::IDD, pParent)
	, m_texto(_T(""))
{

}

CDialogAlerta::~CDialogAlerta()
{
}

void CDialogAlerta::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXTO, m_texto);
}


BEGIN_MESSAGE_MAP(CDialogAlerta, CDialogEx)
END_MESSAGE_MAP()


// CDialogAlerta message handlers
