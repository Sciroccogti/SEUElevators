
// Temp1001View.cpp : CTemp1001View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTemp1001View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTemp1001View ����/����

CTemp1001View::CTemp1001View()
{
	// TODO: �ڴ˴���ӹ������

}

CTemp1001View::~CTemp1001View()
{
}

BOOL CTemp1001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTemp1001View ����

void CTemp1001View::OnDraw(CDC* /*pDC*/)
{
	CTemp1001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTemp1001View ��ӡ


void CTemp1001View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTemp1001View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTemp1001View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTemp1001View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CTemp1001View ���

#ifdef _DEBUG
void CTemp1001View::AssertValid() const
{
	CView::AssertValid();
}

void CTemp1001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTemp1001Doc* CTemp1001View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTemp1001Doc)));
	return (CTemp1001Doc*)m_pDocument;
}
#endif //_DEBUG


// CTemp1001View ��Ϣ�������
