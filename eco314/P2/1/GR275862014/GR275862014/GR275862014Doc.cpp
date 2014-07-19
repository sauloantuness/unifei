
// GR275862014Doc.cpp : implementation of the CGR275862014Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GR275862014.h"
#endif

#include "GR275862014Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGR275862014Doc

IMPLEMENT_DYNCREATE(CGR275862014Doc, CDocument)

BEGIN_MESSAGE_MAP(CGR275862014Doc, CDocument)
END_MESSAGE_MAP()


// CGR275862014Doc construction/destruction

CGR275862014Doc::CGR275862014Doc()
: m_qtd(0)
{
	// TODO: add one-time construction code here

}

CGR275862014Doc::~CGR275862014Doc()
{
}

BOOL CGR275862014Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_relogios.clear();
	
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CGR275862014Doc serialization

void CGR275862014Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_relogios.size();
		for (int i = 0; i < m_relogios.size(); i++)		
			m_relogios[i].Serialize(ar);
		
	}
	else
	{
		m_relogios.clear();
		ar >> m_qtd;
		for (int i = 0; i < m_qtd; i++)
		{
			CRelogio r;
			r.Serialize(ar);
			m_relogios.push_back(r);
		}
		// TODO: add loading code here
	}

}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CGR275862014Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CGR275862014Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CGR275862014Doc::SetSearchContent(const CString& value)
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

// CGR275862014Doc diagnostics

#ifdef _DEBUG
void CGR275862014Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGR275862014Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGR275862014Doc commands


BOOL CGR275862014Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;	

	return TRUE;
}
