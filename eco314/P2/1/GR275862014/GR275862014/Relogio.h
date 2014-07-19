#pragma once
#include "afx.h"
class CRelogio :
	public CObject
{
public:
	CRelogio();
	CRelogio(const CRelogio&);
	~CRelogio();

	CPoint m_pos;
	int m_raio;
	int m_hora;
	int m_min;
	int m_seg;
	CString m_texto;
	COLORREF m_corH;
	COLORREF m_corM;
	COLORREF m_corS;
	CRect m_area;

	void AtualizaArea();

	DECLARE_SERIAL(CRelogio);
	virtual void Serialize(CArchive& ar);

};

