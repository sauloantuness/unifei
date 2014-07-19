#pragma once


// CDialogFator dialog

class CDialogFator : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogFator)

public:
	CDialogFator(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogFator();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float m_fator;
};
