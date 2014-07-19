#include "stdafx.h"
#include "Relogio.h"


CRelogio::CRelogio()
	: m_hora(0)
	, m_min(0)
	, m_seg(0)
	, m_raio(100)
	, m_texto(_T(""))
	, m_pos(0,0)
	, m_corH(RGB(0,0,0))
	, m_corM(RGB(133, 133, 133))
	, m_corS(RGB(255, 0, 0))
{
	AtualizaArea();
}

CRelogio::CRelogio(const CRelogio &r)
{
	m_hora = r.m_hora;
	m_min = r.m_min;
	m_seg = r.m_seg;
	m_raio = r.m_raio;
	m_texto = r.m_texto;
	m_pos = r.m_pos;
	m_corH = r.m_corH;
	m_corM = r.m_corM;
	m_corS = r.m_corS;
}


CRelogio::~CRelogio()
{
}

void CRelogio::AtualizaArea(){
	m_area.SetRect(m_pos.x - m_raio, m_pos.y - m_raio, m_pos.x + m_raio, m_pos.y + m_raio);
	//m_area = CRect(0,0,100,100);
	//m_area.right = 100;
}

IMPLEMENT_SERIAL(CRelogio, CObject, 0);
void CRelogio::Serialize(CArchive& ar){
	if (ar.IsStoring()) {
		ar << m_pos << m_area << m_corH << m_corM << m_corS << m_hora << m_min << m_seg << m_texto << m_raio;
	}
	else {
		ar >> m_pos >> m_area >> m_corH >> m_corM >> m_corS >> m_hora >> m_min >> m_seg >> m_texto >> m_raio;
	}
}