
// Front_EndView.h : CFront_EndView 类的接口
//

#pragma once


class CFront_EndView : public CView
{
protected: // 仅从序列化创建
	CFront_EndView();
	DECLARE_DYNCREATE(CFront_EndView)

// 特性
public:
	CFront_EndDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CFront_EndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Front_EndView.cpp 中的调试版本
inline CFront_EndDoc* CFront_EndView::GetDocument() const
   { return reinterpret_cast<CFront_EndDoc*>(m_pDocument); }
#endif

