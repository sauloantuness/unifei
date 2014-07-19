#pragma once
#include "afx.h"
class CRelogio :
	public CObject
{
public:
	CRelogio();
	CRelogio(const CRelogio &){}
	~CRelogio();
	CTime m_horario;
	int m_raio;


};

