// DialogFator.cpp : implementation file
//

#include "stdafx.h"
#include "lab9.h"
#include "DialogFator.h"
#include "afxdialogex.h"


// CDialogFator dialog

IMPLEMENT_DYNAMIC(CDialogFator, CDialogEx)

CDialogFator::CDialogFator(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogFator::IDD, pParent)
	, m_fator(0.1)
{

}

CDialogFator::~CDialogFator()
{
}

void CDialogFator::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FATOR, m_fator);
}


BEGIN_MESSAGE_MAP(CDialogFator, CDialogEx)
END_MESSAGE_MAP()


// CDialogFator message handlers
