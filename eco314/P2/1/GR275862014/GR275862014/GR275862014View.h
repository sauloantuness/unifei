
// GR275862014View.h : interface of the CGR275862014View class
//

#pragma once

#include "Relogio.h"

class CGR275862014View : public CView
{
protected: // create from serialization only
	CGR275862014View();
	DECLARE_DYNCREATE(CGR275862014View)

// Attributes
public:
	CGR275862014Doc* GetDocument() const;

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
	virtual ~CGR275862014View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void DesenhaRelogio(CRelogio);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int m_linhas;
	afx_msg void OnLinhas();
	afx_msg void OnUpdateLinhas(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer();
	afx_msg void OnUpdateTimer(CCmdUI *pCmdUI);
	int m_timer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // debug version in GR275862014View.cpp
inline CGR275862014Doc* CGR275862014View::GetDocument() const
   { return reinterpret_cast<CGR275862014Doc*>(m_pDocument); }
#endif

