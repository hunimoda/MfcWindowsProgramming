
// Practice_2BView.cpp : implementation of the CPractice2BView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Practice_2B.h"
#endif

#include "Practice_2BDoc.h"
#include "Practice_2BView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice2BView

IMPLEMENT_DYNCREATE(CPractice2BView, CView)

BEGIN_MESSAGE_MAP(CPractice2BView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPractice2BView construction/destruction

CPractice2BView::CPractice2BView() noexcept
{
	// TODO: add construction code here

}

CPractice2BView::~CPractice2BView()
{
}

BOOL CPractice2BView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPractice2BView drawing

void CPractice2BView::OnDraw(CDC *pDC) {
	CPractice2BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;

	pDC->TextOutW(10, 10, m_strWindowSize);

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	m_strMousePosition.Format(_T("마우스 현재 좌표: [%d, %d]"),
														m_ptMousePosition.x, m_ptMousePosition.y);
	pDC->TextOut(m_ptMousePosition.x, m_ptMousePosition.y, m_strMousePosition);
}


// CPractice2BView printing
BOOL CPractice2BView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPractice2BView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPractice2BView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CPractice2BView diagnostics

#ifdef _DEBUG
void CPractice2BView::AssertValid() const
{
	CView::AssertValid();
}

void CPractice2BView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice2BDoc* CPractice2BView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice2BDoc)));
	return (CPractice2BDoc*)m_pDocument;
}
#endif //_DEBUG


// CPractice2BView message handlers


void CPractice2BView::OnSize(UINT nType, int cx, int cy) {
	CView::OnSize(nType, cx, cy);
	m_strWindowSize.Format(_T("윈도우 크기는 너비 %d, 높이 %d입니다."), cx, cy);
	Invalidate();
}


void CPractice2BView::OnLButtonDown(UINT nFlags, CPoint point) {
	m_bMouseDown = true;
	m_strOutput = _T("왼쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CPractice2BView::OnRButtonDown(UINT nFlags, CPoint point) {
	m_strOutput = _T("오른쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CPractice2BView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	m_strOutput = _T("키보드를 눌렀습니다.");
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CPractice2BView::OnMouseMove(UINT nFlags, CPoint point) {
	m_ptMousePosition = point;
	m_strOutput = m_bMouseDown ?
			_T("마우스를 드래그하고 있습니다.") : _T("마우스를 이동 중입니다.");
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CPractice2BView::OnLButtonUp(UINT nFlags, CPoint point) {
	m_bMouseDown = false;
	CView::OnLButtonUp(nFlags, point);
}
