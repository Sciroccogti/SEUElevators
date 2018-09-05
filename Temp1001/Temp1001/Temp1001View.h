
// Temp1001View.h : CTemp1001View 类的接口
//

#pragma once


class CTemp1001View : public CView
{
protected: // 仅从序列化创建
	CTemp1001View();
	DECLARE_DYNCREATE(CTemp1001View)

// 特性
public:
	CTemp1001Doc* GetDocument() const;

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
	virtual ~CTemp1001View();
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

#ifndef _DEBUG  // Temp1001View.cpp 中的调试版本
inline CTemp1001Doc* CTemp1001View::GetDocument() const
   { return reinterpret_cast<CTemp1001Doc*>(m_pDocument); }
#endif

