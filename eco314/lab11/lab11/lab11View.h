
// lab11View.h : interface of the Clab11View class
//

#pragma once
#include "Relogio.h"
#include "atltime.h"

struct Alarme{
	int hora;
	int minuto;
	bool ligado;
	Alarme(int h, int m, bool l=false)
		: hora(h), minuto(m), ligado(l){}
};

class Clab11View : public CView
{
protected: // create from serialization only
	Clab11View();
	DECLARE_DYNCREATE(Clab11View)

// Attributes
public:
	Clab11Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Clab11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	CRelogio m_relogio;
	Alarme m_alarme1;
	Alarme m_alarme2;
	int m_timer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void DesenhaRelogio();
	afx_msg void OnAlarmes();
	void VerificaAlarmes();
	bool m_alerta1;
	bool m_alerta2;
};

#ifndef _DEBUG  // debug version in lab11View.cpp
inline Clab11Doc* Clab11View::GetDocument() const
   { return reinterpret_cast<Clab11Doc*>(m_pDocument); }
#endif

