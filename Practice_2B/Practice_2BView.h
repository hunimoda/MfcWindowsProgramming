
// Practice_2BView.h : interface of the CPractice2BView class
//

#pragma once


class CPractice2BView : public CView
{
protected: // create from serialization only
	CPractice2BView() noexcept;
	DECLARE_DYNCREATE(CPractice2BView)

// Attributes
public:
	CPractice2BDoc* GetDocument() const;

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
	virtual ~CPractice2BView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strWindowSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CString m_strOutput;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	bool m_bMouseDown;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint m_ptMousePosition;
	CString m_strMousePosition;
};

#ifndef _DEBUG  // debug version in Practice_2BView.cpp
inline CPractice2BDoc* CPractice2BView::GetDocument() const
   { return reinterpret_cast<CPractice2BDoc*>(m_pDocument); }
#endif

