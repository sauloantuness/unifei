
// lab10View.h : interface of the Clab10View class
//

#pragma once


class Clab10View : public CView
{
protected: // create from serialization only
	Clab10View();
	DECLARE_DYNCREATE(Clab10View)

// Attributes
public:
	Clab10Doc* GetDocument() const;

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
	virtual ~Clab10View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void DesenhaRetangulo(CRetangulo);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnPlay();
//	afx_msg void OnUpdatePlay(CCmdUI *pCmdUI);
	int m_timer;
};

#ifndef _DEBUG  // debug version in lab10View.cpp
inline Clab10Doc* Clab10View::GetDocument() const
   { return reinterpret_cast<Clab10Doc*>(m_pDocument); }
#endif

