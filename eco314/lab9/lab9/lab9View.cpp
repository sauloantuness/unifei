
// lab9View.cpp : implementation of the Clab9View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "lab9.h"
#endif

#include "lab9Doc.h"
#include "lab9View.h"

#include "DialogFator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab9View

IMPLEMENT_DYNCREATE(Clab9View, CView)

BEGIN_MESSAGE_MAP(Clab9View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_COR, &Clab9View::OnCor)
	ON_COMMAND(ID_FATOR, &Clab9View::OnFator)
	ON_COMMAND(ID_PLAY, &Clab9View::OnPlay)
	ON_COMMAND(ID_STOP, &Clab9View::OnStop)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_STOP, &Clab9View::OnUpdateStop)
	ON_UPDATE_COMMAND_UI(ID_PLAY, &Clab9View::OnUpdatePlay)
END_MESSAGE_MAP()

// Clab9View construction/destruction

Clab9View::Clab9View()
	: m_timer(0)
{
	// TODO: add construction code here

}

Clab9View::~Clab9View()
{
}

BOOL Clab9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Clab9View drawing

void Clab9View::OnDraw(CDC* pDC)
{
	
	Clab9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen pen(PS_SOLID, 3, pDoc->m_cor);
	pDC->SelectObject(pen);

	CRect tela;
	GetClientRect(&tela);
	int x = tela.Width() / 2;
	int y = tela.Height() / 2;
	pDC->MoveTo(x, y);

	for (int i = 0; i < 500; i++)
	{		
		int x1 = x + cos(pDoc->m_t + i * 0.1)* i * pDoc->m_fator;
		int y1 = y + sin(pDoc->m_t + i * 0.1)* i * pDoc->m_fator;
		pDC->LineTo(x1, y1);		
	}

	// TODO: add draw code for native data here
}


// Clab9View printing

BOOL Clab9View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Clab9View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Clab9View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Clab9View diagnostics

#ifdef _DEBUG
void Clab9View::AssertValid() const
{
	CView::AssertValid();
}

void Clab9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab9Doc* Clab9View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab9Doc)));
	return (Clab9Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab9View message handlers


void Clab9View::OnCor()
{
	Clab9Doc *pDoc = GetDocument();

	CColorDialog dlg(pDoc->m_cor);

	if (IDOK == dlg.DoModal()){
		pDoc->m_cor = dlg.GetColor();
		Invalidate();
	}
}


void Clab9View::OnFator()
{
	Clab9Doc *pDoc = GetDocument();
	CDialogFator dlg;
	dlg.m_fator = pDoc->m_fator;

	if (IDOK == dlg.DoModal()){
		pDoc->m_fator = dlg.m_fator;
		Invalidate();
	}
}


void Clab9View::OnPlay()
{
	m_timer = SetTimer(1, 100, NULL);
}


void Clab9View::OnStop()
{
	if (m_timer){
		KillTimer(m_timer);
		m_timer = 0;
	}
		
	// TODO: Add your command handler code here
}


void Clab9View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Clab9Doc *pDoc = GetDocument();
	pDoc->m_t += -0.2;
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void Clab9View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	if (m_timer)
		KillTimer(m_timer);
	m_timer;
}


void Clab9View::OnUpdateStop(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_timer == 0)
		pCmdUI->Enable(0);
}


void Clab9View::OnUpdatePlay(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_timer)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(0);
}
