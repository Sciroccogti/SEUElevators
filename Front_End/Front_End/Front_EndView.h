
// Front_EndView.h : CFront_EndView ��Ľӿ�
//

#pragma once


class CFront_EndView : public CView
{
protected: // �������л�����
	CFront_EndView();
	DECLARE_DYNCREATE(CFront_EndView)

// ����
public:
	CFront_EndDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFront_EndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Front_EndView.cpp �еĵ��԰汾
inline CFront_EndDoc* CFront_EndView::GetDocument() const
   { return reinterpret_cast<CFront_EndDoc*>(m_pDocument); }
#endif

