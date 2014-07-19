// DialogRelogio.cpp : implementation file
//

#include "stdafx.h"
#include "GR275862014.h"
#include "DialogRelogio.h"
#include "afxdialogex.h"


// CDialogRelogio dialog

IMPLEMENT_DYNAMIC(CDialogRelogio, CDialogEx)

CDialogRelogio::CDialogRelogio(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogRelogio::IDD, pParent)
	, m_x(0)
	, m_y(0)
	, m_hora(10)
	, m_min(15)
	, m_seg(30)
	, m_raio(50)
	, m_texto(_T("12:00:00"))
{

}

CDialogRelogio::~CDialogRelogio()
{
}

void CDialogRelogio::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CENTROX, m_x);
	DDX_Text(pDX, IDC_CENTROY, m_y);
	DDX_Text(pDX, IDC_HORA, m_hora);
	DDX_Text(pDX, IDC_MIN, m_min);
	DDX_Text(pDX, IDC_SEG, m_seg);
	DDX_Text(pDX, IDC_RAIO, m_raio);
	DDX_Text(pDX, IDC_TEXTO, m_texto);
}


BEGIN_MESSAGE_MAP(CDialogRelogio, CDialogEx)
END_MESSAGE_MAP()


// CDialogRelogio message handlers
