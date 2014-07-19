#pragma once


// CDialogAlerta dialog

class CDialogAlerta : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogAlerta)

public:
	CDialogAlerta(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogAlerta();

// Dialog Data
	enum { IDD = IDD_ALERTA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_texto;
};
