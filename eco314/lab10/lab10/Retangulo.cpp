#include "stdafx.h"
#include "Retangulo.h"

CRetangulo::CRetangulo()
	: m_altura(50)
	, m_largura(50)
	, m_pos(25,25)
	, m_pen(RGB(rand() % 255, rand() % 255, rand() % 255))
	, m_brush(RGB(rand() % 255, rand() % 255, rand() % 255))
	, m_sentidoX(1)
	, m_sentidoY(1)
{
	AtualizaArea();
}

CRetangulo::CRetangulo(const CRetangulo& r)
{
	m_altura = r.m_altura;
	m_largura = r.m_largura;
	m_pos = r.m_pos;
	m_area = r.m_area;
	m_pen = r.m_pen;
	m_brush = r.m_brush;
	m_sentidoX = r.m_sentidoX;
	m_sentidoY = r.m_sentidoY;
}

CRetangulo::~CRetangulo()
{
}

void CRetangulo::AtualizaArea(){
	m_area.SetRect(m_pos.x - m_largura / 2, m_pos.y - m_altura / 2, m_pos.x + m_largura / 2, m_pos.y + m_altura / 2);
}

void CRetangulo::AtualizaPosicao(){
	m_pos.x += m_sentidoX;
	m_pos.y += m_sentidoY;
	AtualizaArea();
}

void CRetangulo::AtualizaCor(){
	m_pen = RGB(rand() % 255, rand() % 255, rand() % 255);
	m_brush = RGB(rand() % 255, rand() % 255, rand() % 255);
}

IMPLEMENT_SERIAL(CRetangulo, CObject, 0)

void CRetangulo::Serialize(CArchive& ar)
{	
	if (ar.IsStoring()) {				
		ar << m_altura << m_largura << m_pos << m_area << m_pen << m_brush << m_sentidoX << m_sentidoY;	
	}
	else {
		
		ar >> m_altura >> m_largura >> m_pos >> m_area >> m_pen >> m_brush >> m_sentidoX >> m_sentidoY;
	}
}