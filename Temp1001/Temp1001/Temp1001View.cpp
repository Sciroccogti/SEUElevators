
// Temp1001View.cpp : CTemp1001View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Temp1001.h"
#endif

#include "Temp1001Doc.h"
#include "Temp1001View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTemp1001View

IMPLEMENT_DYNCREATE(CTemp1001View, CView)

BEGIN_MESSAGE_MAP(CTemp1001View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTemp1001View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTemp1001View 构造/析构

CTemp1001View::CTemp1001View()
{
	// TODO: 在此处添加构造代码

}

CTemp1001View::~CTemp1001View()
{
}

BOOL CTemp1001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTemp1001View 绘制

void CTemp1001View::OnDraw(CDC* /*pDC*/)
{
	CTemp1001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CTemp1001View 打印


void CTemp1001View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTemp1001View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTemp1001View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTemp1001View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CTemp1001View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTemp1001View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTemp1001View 诊断

#ifdef _DEBUG
void CTemp1001View::AssertValid() const
{
	CView::AssertValid();
}

void CTemp1001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTemp1001Doc* CTemp1001View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTemp1001Doc)));
	return (CTemp1001Doc*)m_pDocument;
}
#endif //_DEBUG


// CTemp1001View 消息处理程序
