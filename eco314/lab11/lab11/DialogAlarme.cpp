// DialogAlarme.cpp : implementation file
//

#include "stdafx.h"
#include "lab11.h"
#include "DialogAlarme.h"
#include "afxdialogex.h"


// CDialogAlarme dialog

IMPLEMENT_DYNAMIC(CDialogAlarme, CDialogEx)

CDialogAlarme::CDialogAlarme(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogAlarme::IDD, pParent)
	, m_hora1(0)
	, m_minuto1(0)
	, m_ligado1(FALSE)
	, m_ligado2(FALSE)
{

}

CDialogAlarme::~CDialogAlarme()
{
}

void CDialogAlarme::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HORA1, m_hora1);
	DDV_MinMaxInt(pDX, m_hora1, 0, 23);
	DDX_Text(pDX, IDC_HORA2, m_hora2);
	DDV_MinMaxInt(pDX, m_hora2, 0, 23);
	DDX_Text(pDX, IDC_MINUTO1, m_minuto1);
	DDV_MinMaxInt(pDX, m_minuto1, 0, 59);
	DDX_Text(pDX, IDC_MINUTO2, m_minuto2);
	DDV_MinMaxInt(pDX, m_minuto2, 0, 59);
	DDX_Check(pDX, IDC_LIGADO1, m_ligado1);
	DDX_Check(pDX, IDC_LIGADO2, m_ligado2);
}


BEGIN_MESSAGE_MAP(CDialogAlarme, CDialogEx)
END_MESSAGE_MAP()


// CDialogAlarme message handlers
