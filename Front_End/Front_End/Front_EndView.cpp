
// Front_EndView.cpp : CFront_EndView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFront_EndView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFront_EndView ����/����

CFront_EndView::CFront_EndView()
{
	// TODO: �ڴ˴���ӹ������

}

CFront_EndView::~CFront_EndView()
{
}

BOOL CFront_EndView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFront_EndView ����

void CFront_EndView::OnDraw(CDC* pDC)
{
	CFront_EndDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CFront_EndView ��ӡ


void CFront_EndView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFront_EndView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFront_EndView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFront_EndView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CFront_EndView ���

#ifdef _DEBUG
void CFront_EndView::AssertValid() const
{
	CView::AssertValid();
}

void CFront_EndView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFront_EndDoc* CFront_EndView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFront_EndDoc)));
	return (CFront_EndDoc*)m_pDocument;
}
#endif //_DEBUG


// CFront_EndView ��Ϣ�������
