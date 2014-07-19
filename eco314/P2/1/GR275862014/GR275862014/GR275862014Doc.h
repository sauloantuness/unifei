
// GR275862014Doc.h : interface of the CGR275862014Doc class
//


#pragma once
#include "Relogio.h"
#include <vector>

class CGR275862014Doc : public CDocument
{
protected: // create from serialization only
	CGR275862014Doc();
	DECLARE_DYNCREATE(CGR275862014Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CGR275862014Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	int m_qtd;
	std::vector<CRelogio> m_relogios;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};
