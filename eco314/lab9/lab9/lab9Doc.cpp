
// lab9Doc.cpp : implementation of the Clab9Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "lab9.h"
#endif

#include "lab9Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Clab9Doc

IMPLEMENT_DYNCREATE(Clab9Doc, CDocument)

BEGIN_MESSAGE_MAP(Clab9Doc, CDocument)
END_MESSAGE_MAP()


// Clab9Doc construction/destruction

Clab9Doc::Clab9Doc()
	: m_fator(0.5)
	, m_t(0)
	, m_cor(RGB(255,0,0))
{
	// TODO: add one-time construction code here

}

Clab9Doc::~Clab9Doc()
{
}

BOOL Clab9Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_t = 0;
	m_fator = 0.5;
	m_cor = RGB(255, 0, 0);
	
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// Clab9Doc serialization

void Clab9Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_cor << m_fator << m_t;
	}
	else
	{
		ar >> m_cor >> m_fator >> m_t;
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void Clab9Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void Clab9Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Clab9Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Clab9Doc diagnostics

#ifdef _DEBUG
void Clab9Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Clab9Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Clab9Doc commands
