
// Practice_2AView.cpp : implementation of the CPractice2AView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Practice_2A.h"
#endif

#include "Practice_2ADoc.h"
#include "Practice_2AView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice2AView

IMPLEMENT_DYNCREATE(CPractice2AView, CView)

BEGIN_MESSAGE_MAP(CPractice2AView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPractice2AView construction/destruction

CPractice2AView::CPractice2AView() noexcept
{
	// TODO: add construction code here

}

CPractice2AView::~CPractice2AView()
{
}

BOOL CPractice2AView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPractice2AView drawing

void CPractice2AView::OnDraw(CDC* /*pDC*/)
{
	CPractice2ADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPractice2AView printing

BOOL CPractice2AView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPractice2AView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPractice2AView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CPractice2AView diagnostics

#ifdef _DEBUG
void CPractice2AView::AssertValid() const
{
	CView::AssertValid();
}

void CPractice2AView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice2ADoc* CPractice2AView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice2ADoc)));
	return (CPractice2ADoc*)m_pDocument;
}
#endif //_DEBUG


// CPractice2AView message handlers
