
// Practice_2AView.h : interface of the CPractice2AView class
//

#pragma once


class CPractice2AView : public CView
{
protected: // create from serialization only
	CPractice2AView() noexcept;
	DECLARE_DYNCREATE(CPractice2AView)

// Attributes
public:
	CPractice2ADoc* GetDocument() const;

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
	virtual ~CPractice2AView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Practice_2AView.cpp
inline CPractice2ADoc* CPractice2AView::GetDocument() const
   { return reinterpret_cast<CPractice2ADoc*>(m_pDocument); }
#endif

