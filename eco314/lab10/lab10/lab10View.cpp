
// lab10View.cpp : implementation of the Clab10View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "lab10.h"
#endif

#include "lab10Doc.h"
#include "lab10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab10View

IMPLEMENT_DYNCREATE(Clab10View, CView)

BEGIN_MESSAGE_MAP(Clab10View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Clab10View construction/destruction

Clab10View::Clab10View()
	: m_timer(0)
{
	// TODO: add construction code here

}

Clab10View::~Clab10View()
{
}

BOOL Clab10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Clab10View drawing

void Clab10View::OnDraw(CDC* pDC)
{
	Clab10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect tela;
	GetClientRect(&tela);

	if (pDoc->m_retangulo.m_area.right > tela.right||
		pDoc->m_retangulo.m_area.left < tela.left){
		pDoc->m_retangulo.m_sentidoX *= -1;
		pDoc->m_retangulo.AtualizaCor();
	}

	if (pDoc->m_retangulo.m_area.bottom > tela.bottom ||
		pDoc->m_retangulo.m_area.top < tela.top){
		pDoc->m_retangulo.m_sentidoY *= -1;
		pDoc->m_retangulo.AtualizaCor();
	}
		
	DesenhaRetangulo(pDoc->m_retangulo);

	// TODO: add draw code for native data here
}


// Clab10View printing

BOOL Clab10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Clab10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Clab10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Clab10View diagnostics

#ifdef _DEBUG
void Clab10View::AssertValid() const
{
	CView::AssertValid();
}

void Clab10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab10Doc* Clab10View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab10Doc)));
	return (Clab10Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab10View message handlers


void Clab10View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	
	SetTimer(1, 10, NULL);

	// TODO: Add your specialized code here and/or call the base class
}


void Clab10View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Clab10Doc* pDoc = GetDocument();
	pDoc->m_retangulo.AtualizaPosicao();
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void Clab10View::DesenhaRetangulo(CRetangulo r)
{
	Clab10Doc *pDoc = GetDocument();
	CDC *pDC = GetDC();

	CBrush brush(r.m_brush);
	CPen pen(PS_SOLID, 4, r.m_pen);

	pDC->SelectObject(brush);
	pDC->SelectObject(pen);

	pDC->Rectangle(r.m_area);
	ReleaseDC(pDC);
}


void Clab10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	Clab10Doc *pDoc = GetDocument();
	pDoc->m_retangulo.m_pos = point;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


//void Clab10View::OnPlay()
//{
//	// TODO: Add your command handler code here
//	if (m_timer){
//		KillTimer(m_timer);
//		m_timer = 0;
//	}
//	else{
//		m_timer = SetTimer(1, 1, NULL);
//	}
//	
//}


//void Clab10View::OnUpdatePlay(CCmdUI *pCmdUI)
//{
//	if (m_timer)
//		pCmdUI->SetCheck(1);
//	else
//		pCmdUI->SetCheck(0);
//}
