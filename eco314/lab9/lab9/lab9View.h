
// lab9View.h : interface of the Clab9View class
//

#pragma once


class Clab9View : public CView
{
protected: // create from serialization only
	Clab9View();
	DECLARE_DYNCREATE(Clab9View)

// Attributes
public:
	Clab9Doc* GetDocument() const;

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
	virtual ~Clab9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCor();
	afx_msg void OnFator();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	int m_timer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	afx_msg void OnUpdateStop(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePlay(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in lab9View.cpp
inline Clab9Doc* Clab9View::GetDocument() const
   { return reinterpret_cast<Clab9Doc*>(m_pDocument); }
#endif

