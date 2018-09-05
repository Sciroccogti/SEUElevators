
// Front_EndView.cpp : CFront_EndView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Front_End.h"
#endif

#include "Front_EndDoc.h"
#include "Front_EndView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFront_EndView

IMPLEMENT_DYNCREATE(CFront_EndView, CView)

BEGIN_MESSAGE_MAP(CFront_EndView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFront_EndView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFront_EndView 构造/析构

CFront_EndView::CFront_EndView()
{
	// TODO: 在此处添加构造代码

}

CFront_EndView::~CFront_EndView()
{
}

BOOL CFront_EndView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFront_EndView 绘制

void CFront_EndView::OnDraw(CDC* pDC)
{
	CFront_EndDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CBitmap m_bmp;
	m_bmp.LoadBitmapW(IDB_BITMAP1);
	BITMAP bm;
	m_bmp.GetObject(sizeof(BITMAP),&bm);
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	CBitmap* pOldbmp = dcMem.SelectObject(&m_bmp);
	pDC->BitBlt(0,0,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);

	dcMem.SelectObject(pOldbmp);
}


// CFront_EndView 打印


void CFront_EndView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFront_EndView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFront_EndView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFront_EndView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CFront_EndView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFront_EndView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFront_EndView 诊断

#ifdef _DEBUG
void CFront_EndView::AssertValid() const
{
	CView::AssertValid();
}

void CFront_EndView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFront_EndDoc* CFront_EndView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFront_EndDoc)));
	return (CFront_EndDoc*)m_pDocument;
}
#endif //_DEBUG


// CFront_EndView 消息处理程序
