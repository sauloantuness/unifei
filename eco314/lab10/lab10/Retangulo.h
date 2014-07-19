#pragma once
#include "afx.h"
class CRetangulo :
	public CObject
{
public:
	CRetangulo();
	CRetangulo(const CRetangulo&);
	~CRetangulo();

	int m_altura;
	int m_largura;
	int m_sentidoX;
	int m_sentidoY;
	CPoint m_pos;
	CRect m_area;
	COLORREF m_pen;
	COLORREF m_brush;

	void AtualizaArea();
	void AtualizaPosicao();
	void AtualizaCor();

	DECLARE_SERIAL(CRetangulo);
	virtual void Serialize(CArchive& ar);
};

