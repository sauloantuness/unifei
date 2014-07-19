
// GR275862014View.cpp : implementation of the CGR275862014View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GR275862014.h"
#endif

#include "GR275862014Doc.h"
#include "GR275862014View.h"
#include "DialogRelogio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGR275862014View

IMPLEMENT_DYNCREATE(CGR275862014View, CView)

BEGIN_MESSAGE_MAP(CGR275862014View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_LINHAS, &CGR275862014View::OnLinhas)
	ON_UPDATE_COMMAND_UI(ID_LINHAS, &CGR275862014View::OnUpdateLinhas)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_TIMER, &CGR275862014View::OnTimer)
	ON_UPDATE_COMMAND_UI(ID_TIMER, &CGR275862014View::OnUpdateTimer)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CGR275862014View construction/destruction

CGR275862014View::CGR275862014View()
: m_linhas(0)
, m_timer(0)
{
	// TODO: add construction code here

}

CGR275862014View::~CGR275862014View()
{
}

BOOL CGR275862014View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGR275862014View drawing

void CGR275862014View::OnDraw(CDC* pDC)
{
	CGR275862014Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (m_linhas && pDoc->m_relogios.size()){
		for (int i = 0; i < pDoc->m_relogios.size() - 1; i++){
			pDC->MoveTo(pDoc->m_relogios[i].m_pos);
			pDC->LineTo(pDoc->m_relogios[i+1].m_pos);
		}
	}

	for (int i = 0; i < pDoc->m_relogios.size(); i++)
		DesenhaRelogio(pDoc->m_relogios[i]);

	// TODO: add draw code for native data here
}


// CGR275862014View printing

BOOL CGR275862014View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGR275862014View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGR275862014View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CGR275862014View diagnostics

#ifdef _DEBUG
void CGR275862014View::AssertValid() const
{
	CView::AssertValid();
}

void CGR275862014View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGR275862014Doc* CGR275862014View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGR275862014Doc)));
	return (CGR275862014Doc*)m_pDocument;
}
#endif //_DEBUG


// CGR275862014View message handlers


void CGR275862014View::DesenhaRelogio(CRelogio r)
{
	CDC *pDC = GetDC();

	CBrush brush(RGB(250, 250, 250)), *pBrush;
	CPen pen(PS_SOLID, 3, RGB(0, 0, 0)), *pPen;

	pBrush = pDC->SelectObject(&brush);
	pPen = pDC->SelectObject(&pen);

	pDC->MoveTo(r.m_pos);
	pDC->Ellipse(r.m_pos.x - r.m_raio, r.m_pos.y - r.m_raio, r.m_pos.x + r.m_raio, r.m_pos.y + r.m_raio);

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->SetTextAlign(TA_CENTER);
	pDC->TextOutW(r.m_pos.x, r.m_pos.y - r.m_raio - 16, r.m_texto);

	// Tempo
	CTime hora = CTime::GetCurrentTime();
	//CTime hora = GetCurrentTime();
	int h = r.m_hora;
	int m = r.m_min;
	int s = r.m_seg;
	float f_h = 0.50 * r.m_raio;
	float f_m = 0.80 * r.m_raio;
	float f_s = 0.95 * r.m_raio;

	// Ponteiro
	float x, y, ang;
	CPen penH(1, 3, r.m_corH);
	CPen *oldPen;
	oldPen = pDC->SelectObject(&penH);

	// Hora
	ang = 3.14 / 180 * (h - 15) * 30;
	x = cos((float)ang) * f_h;
	y = sin((float)ang) * f_h;

	pDC->MoveTo(r.m_pos);
	pDC->LineTo(r.m_pos.x + x, r.m_pos.y + y);

	// Min
	CPen penM(1, 3, r.m_corM);
	pDC->SelectObject(&penM);
	ang = 3.14 / 180 * (m - 15) * 6;
	x = cos((float)ang) * f_m;
	y = sin((float)ang) * f_m;
	pDC->MoveTo(r.m_pos);
	pDC->LineTo(r.m_pos.x + x, r.m_pos.y + y);

	// Seg
	CPen penS(6, 1, r.m_corS);
	pDC->SelectObject(penS);
	ang = 3.14 / 180 * (s - 15) * 6;
	x = cos((float)ang) * f_s;
	y = sin((float)ang) * f_s;
	pDC->MoveTo(r.m_pos);
	pDC->LineTo(r.m_pos.x + x, r.m_pos.y + y);

	ReleaseDC(pDC);
}


void CGR275862014View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CGR275862014Doc *pDoc = GetDocument();

	if (pDoc->m_relogios.size() < 10){
		
		CDialogRelogio dlg;

		dlg.m_x = point.x;
		dlg.m_y = point.y;		

		if (IDOK == dlg.DoModal()){
			CRelogio r;			
			r.m_pos.x = dlg.m_x;
			r.m_pos.y = dlg.m_y;
			r.m_raio = dlg.m_raio;
			r.m_texto = dlg.m_texto;
			r.m_hora = dlg.m_hora;
			r.m_min = dlg.m_min;
			r.m_seg = dlg.m_seg;
			r.AtualizaArea();			
			pDoc->m_relogios.push_back(r);

			Invalidate();
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CGR275862014View::OnLinhas()
{
	if (m_linhas)
		m_linhas = 0;
	else
		m_linhas = 1;		
	
	Invalidate();
}


void CGR275862014View::OnUpdateLinhas(CCmdUI *pCmdUI)
{
	if (m_linhas)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void CGR275862014View::OnRButtonDown(UINT nFlags, CPoint point)
{
	CGR275862014Doc *pDoc = GetDocument();
	
	if (pDoc->m_relogios.size()){
		
		for (int i = 0; i < pDoc->m_relogios.size(); i++){			
			pDoc->m_relogios[i].AtualizaArea();
			CRgn r;
			r.CreateEllipticRgnIndirect(pDoc->m_relogios[i].m_area);			
						
			if (r.PtInRegion(point)){
				
				CDialogRelogio dlg;
				dlg.m_x = pDoc->m_relogios[i].m_pos.x;
				dlg.m_y = pDoc->m_relogios[i].m_pos.y;
				dlg.m_raio = pDoc->m_relogios[i].m_raio;
				dlg.m_texto = pDoc->m_relogios[i].m_texto;
				dlg.m_hora = pDoc->m_relogios[i].m_hora;
				dlg.m_min = pDoc->m_relogios[i].m_min;
				dlg.m_seg = pDoc->m_relogios[i].m_seg;
				if (IDOK == dlg.DoModal()){
					pDoc->m_relogios[i].m_pos.x = dlg.m_x;
					pDoc->m_relogios[i].m_pos.y = dlg.m_y;
					pDoc->m_relogios[i].m_raio = dlg.m_raio;
					pDoc->m_relogios[i].m_texto = dlg.m_texto;
					pDoc->m_relogios[i].m_hora = dlg.m_hora;
					pDoc->m_relogios[i].m_min = dlg.m_min;
					pDoc->m_relogios[i].m_seg = dlg.m_seg;

					pDoc->m_relogios[i].AtualizaArea();
					Invalidate();
					break;
				}
			}
		}
	}

	CView::OnRButtonDown(nFlags, point);
}


void CGR275862014View::OnTimer()
{
	// TODO: Add your command handler code here
	if (m_timer){
		KillTimer(m_timer);
		m_timer = 0;
	}
	else{
		m_timer = SetTimer(1, 1000, NULL);		
	}
}

void CGR275862014View::OnUpdateTimer(CCmdUI *pCmdUI)
{
	if (m_timer){
		pCmdUI->SetCheck(1);
	}		
	else{
		pCmdUI->SetCheck(0);
	}
}


void CGR275862014View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CGR275862014Doc *pDoc = GetDocument();

	if (pDoc->m_relogios.size()){
		for (int i = 0; i < pDoc->m_relogios.size(); i++)
		{
			pDoc->m_relogios[i].m_seg++;
			if (pDoc->m_relogios[i].m_seg == 60){
				pDoc->m_relogios[i].m_seg = 0;
				pDoc->m_relogios[i].m_min++;
				if (pDoc->m_relogios[i].m_min == 60){
					pDoc->m_relogios[i].m_min = 0;
					pDoc->m_relogios[i].m_hora++;
					if (pDoc->m_relogios[i].m_hora == 12){
						pDoc->m_relogios[i].m_hora = 0;
					}
				}
			}
		}
	}
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CGR275862014View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
}
