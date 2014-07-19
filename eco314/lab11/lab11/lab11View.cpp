
// lab11View.cpp : implementation of the Clab11View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "lab11.h"
#endif

#include "lab11Doc.h"
#include "lab11View.h"
#include "DialogAlarme.h"
#include "DialogAlerta.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab11View

IMPLEMENT_DYNCREATE(Clab11View, CView)

BEGIN_MESSAGE_MAP(Clab11View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_COMMAND(ID_ALARMES, &Clab11View::OnAlarmes)
END_MESSAGE_MAP()

// Clab11View construction/destruction

Clab11View::Clab11View()
	: m_alarme1(0,0)
	, m_alarme2(0,0)
	, m_timer(0)
	, m_alerta1(false)
	, m_alerta2(false)
{
	// TODO: add construction code here

}

Clab11View::~Clab11View()
{
}

BOOL Clab11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Clab11View drawing

void Clab11View::OnDraw(CDC* pDC)
{
	Clab11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	DesenhaRelogio();

		
	

	// TODO: add draw code for native data here
}


// Clab11View printing

BOOL Clab11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Clab11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Clab11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Clab11View diagnostics

#ifdef _DEBUG
void Clab11View::AssertValid() const
{
	CView::AssertValid();
}

void Clab11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab11Doc* Clab11View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab11Doc)));
	return (Clab11Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab11View message handlers


void Clab11View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_relogio.m_horario = CTime::GetCurrentTime();
	SetTimer(m_timer, 1000, NULL);

	// TODO: Add your specialized code here and/or call the base class
}


void Clab11View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	m_relogio.m_horario += 1;
	Invalidate();

	if (!m_alerta1 || !m_alerta2)
		VerificaAlarmes();

	CView::OnTimer(nIDEvent);
}


void Clab11View::DesenhaRelogio()
{
	CDC *pDC = GetDC();
	CRect tela;

	GetClientRect(&tela);
	CPoint centro = tela.CenterPoint();

	CBrush brush(RGB(240, 240, 240));
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));

	pDC->SelectObject(pen);
	pDC->SelectObject(brush);

	pDC->Ellipse(centro.x - m_relogio.m_raio, centro.y - m_relogio.m_raio, centro.x + m_relogio.m_raio, centro.y + m_relogio.m_raio);

	float s = 0.9 * m_relogio.m_raio;
	float m = 0.8 * m_relogio.m_raio;
	float h = 0.4 * m_relogio.m_raio;

	int seg = m_relogio.m_horario.GetSecond();
	int min = m_relogio.m_horario.GetMinute();
	int hora = m_relogio.m_horario.GetHour() % 12;

	int x = s * sin((180 - (seg * 6)) * 3.14 / 180);
	int y = s * cos((180 - (seg * 6)) * 3.14 / 180);
	
	CPen pen2(PS_SOLID, 1, RGB(255, 20, 20));
	pDC->SelectObject(pen2);
	pDC->MoveTo(centro);
	pDC->LineTo(centro.x + x, centro.y + y);
	pDC->MoveTo(centro);
	pDC->LineTo(centro.x - x * 0.2, centro.y - y * 0.2);

	x = m * sin((180 - (min * 6)) * 3.14 / 180);
	y = m * cos((180 - (min * 6)) * 3.14 / 180);

	CPen pen3(PS_SOLID, 3, RGB(30, 20, 20));
	pDC->SelectObject(pen3);
	pDC->MoveTo(centro);
	pDC->LineTo(centro.x + x, centro.y + y);

	x = h * sin((180 - (hora * 30) - (min/2)) * 3.14 / 180);
	y = h * cos((180 - (hora * 30) - (min/2)) * 3.14 / 180);
	pDC->MoveTo(centro);
	pDC->LineTo(centro.x + x, centro.y + y);

	ReleaseDC(pDC);
}


void Clab11View::OnAlarmes()
{
	CDialogAlarme dlg;

	dlg.m_hora1 = m_alarme1.hora;
	dlg.m_minuto1 = m_alarme1.minuto;
	dlg.m_ligado1 = m_alarme1.ligado;
	
	dlg.m_hora2 = m_alarme2.hora;
	dlg.m_minuto2 = m_alarme2.minuto;
	dlg.m_ligado2 = m_alarme2.ligado;

	if (IDOK == dlg.DoModal()){
		m_alarme1.hora = dlg.m_hora1;
		m_alarme1.minuto = dlg.m_minuto1;
		m_alarme1.ligado = dlg.m_ligado1;
		m_alarme2.hora = dlg.m_hora2;
		m_alarme2.minuto = dlg.m_minuto2;
		m_alarme2.ligado = dlg.m_ligado2;
	}
}


void Clab11View::VerificaAlarmes()
{
	if (m_alarme1.ligado &&
		m_relogio.m_horario.GetHour() == m_alarme1.hora &&
		m_relogio.m_horario.GetMinute() == m_alarme1.minuto){

		m_alarme1.ligado = 0;
		m_alerta1 = 1;
		CDialogAlerta dlg;
		dlg.m_texto = ("ALARME 1");
		if (IDOK == dlg.DoModal())
			m_alerta1 = 0;
	}

	if (m_alarme2.ligado &&
		m_relogio.m_horario.GetHour() == m_alarme2.hora &&
		m_relogio.m_horario.GetMinute() == m_alarme2.minuto){

		m_alarme2.ligado = 0;
		m_alerta2 = 1;
		CDialogAlerta dlg;
		dlg.m_texto = (CString)("ALARME 2");
		if (IDOK == dlg.DoModal())
			m_alerta2 = 0;
	}
}
