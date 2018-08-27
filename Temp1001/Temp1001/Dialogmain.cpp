// Dialogmain.cpp : 实现文件
//

#include "stdafx.h"
#include "Temp1001.h"
#include "Dialogmain.h"
#include "afxdialogex.h"


// CDialogmain 对话框

IMPLEMENT_DYNAMIC(CDialogmain, CDialogEx)

CDialogmain::CDialogmain(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogmain::IDD, pParent)
{

	m_Flrnum1 = 0;
	m_Flrnum10 = 0;
	m_Flrnum11 = 0;
	m_Flrnum12 = 0;
	m_Flrnum13 = 0;
	m_Flrnum14 = 0;
	m_Flrnum15 = 0;
	m_Flrnum16 = 0;
	m_Flrnum17 = 0;
	m_Flrnum18 = 0;
	m_Flrnum19 = 0;
	m_Flrnum2 = 0;
	m_Flrnum20 = 0;
	m_Flrnum3 = 0;
	m_Flrnum4 = 0;
	m_Flrnum5 = 0;
	m_Flrnum6 = 0;
	m_Flrnum7 = 0;
	m_Flrnum8 = 0;
	m_Flrnum9 = 0;
	m_Refreshnum = 0;
	m_Transnum = 0;
}

CDialogmain::~CDialogmain()
{
}

void CDialogmain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONDITION1, m_EditCondition1);
	DDX_Control(pDX, IDC_CONDITION2, m_EditCondition2);
	DDX_Control(pDX, IDC_CONDITION3, m_EditCondition3);
	DDX_Text(pDX, IDC_FLRNUM1, m_Flrnum1);
	DDX_Text(pDX, IDC_FLRNUM10, m_Flrnum10);
	DDX_Text(pDX, IDC_FLRNUM11, m_Flrnum11);
	DDX_Text(pDX, IDC_FLRNUM12, m_Flrnum12);
	DDX_Text(pDX, IDC_FLRNUM13, m_Flrnum13);
	DDX_Text(pDX, IDC_FLRNUM14, m_Flrnum14);
	DDX_Text(pDX, IDC_FLRNUM15, m_Flrnum15);
	DDX_Text(pDX, IDC_FLRNUM16, m_Flrnum16);
	DDX_Text(pDX, IDC_FLRNUM17, m_Flrnum17);
	DDX_Text(pDX, IDC_FLRNUM18, m_Flrnum18);
	DDX_Text(pDX, IDC_FLRNUM19, m_Flrnum19);
	DDX_Text(pDX, IDC_FLRNUM2, m_Flrnum2);
	DDX_Text(pDX, IDC_FLRNUM20, m_Flrnum20);
	DDX_Text(pDX, IDC_FLRNUM3, m_Flrnum3);
	DDX_Text(pDX, IDC_FLRNUM4, m_Flrnum4);
	DDX_Text(pDX, IDC_FLRNUM5, m_Flrnum5);
	DDX_Text(pDX, IDC_FLRNUM6, m_Flrnum6);
	DDX_Text(pDX, IDC_FLRNUM7, m_Flrnum7);
	DDX_Text(pDX, IDC_FLRNUM8, m_Flrnum8);
	DDX_Text(pDX, IDC_FLRNUM9, m_Flrnum9);
	DDX_Text(pDX, IDC_REFRESH, m_Refreshnum);
	DDX_Text(pDX, IDC_TRANS, m_Transnum);
}


BEGIN_MESSAGE_MAP(CDialogmain, CDialogEx)
	ON_BN_CLICKED(IDC_START, &CDialogmain::OnClickedStart)
	ON_BN_CLICKED(IDOK, &CDialogmain::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogmain 消息处理程序

/******************************************************************************************/
void CDialogmain::OnClickedStart()            /////程序启动函数；此后所有运算都在此后运行
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDialogmain::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
