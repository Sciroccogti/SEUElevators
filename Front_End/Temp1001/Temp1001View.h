
// Temp1001View.h : CTemp1001View ��Ľӿ�
//

#pragma once


class CTemp1001View : public CView
{
protected: // �������л�����
	CTemp1001View();
	DECLARE_DYNCREATE(CTemp1001View)

// ����
public:
	CTemp1001Doc* GetDocument() const;

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
	virtual ~CTemp1001View();
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

#ifndef _DEBUG  // Temp1001View.cpp �еĵ��԰汾
inline CTemp1001Doc* CTemp1001View::GetDocument() const
   { return reinterpret_cast<CTemp1001Doc*>(m_pDocument); }
#endif

