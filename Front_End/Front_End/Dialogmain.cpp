// Dialogmain.cpp : 实现文件
#include "stdafx.h"
#include "Front_End.h"
#include "Dialogmain.h"
#include "afxdialogex.h"
#include "People.h"
#include "windows.h"

// CDialogmain 对话框
int n[L + 1];
IMPLEMENT_DYNAMIC(CDialogmain, CDialogEx)

CDialogmain::CDialogmain(CWnd *pParent)
	: CDialogEx(CDialogmain::IDD, pParent), Vtime(0), v(1)
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
	m_time1 = 0;
	m_time3 = 0;
	m_time2 = 0;
	for (int i = 0; i < 3; i++)
	{
		m_PreFlr[i] = 0;
		m_PreFrontFlr[i] = 0;
	}
	m_objflr1 = 0;
	m_objflr2 = 0;
	m_objflr3 = 0;
	m_preflr1 = 0.0;
	m_preflr2 = 0.0;
	m_preflr3 = 0.0;
	m_acc = 0;
	m_Total1 = 0;
	m_Total2 = 0;
	m_Total3 = 0;
	mass = 0;
	m_mass = 0;
}

CDialogmain::~CDialogmain()
{
}

void CDialogmain::DoDataExchange(CDataExchange *pDX)
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
	DDX_Control(pDX, IDC_ELE1, m_PrEle1);
	DDX_Control(pDX, IDC_ELE2, m_PrEle2);
	DDX_Control(pDX, IDC_ELE3, m_PrEle3);
	DDX_Text(pDX, IDC_TIME1, m_time1);
	DDX_Text(pDX, IDC_TIME3, m_time3);
	DDX_Text(pDX, IDC_EDIT2, m_time2);
	DDX_Text(pDX, IDC_OBJFLR1, m_objflr1);
	DDX_Text(pDX, IDC_OBJFLR2, m_objflr2);
	DDX_Text(pDX, IDC_OBJFLR3, m_objflr3);
	DDX_Text(pDX, IDC_PREFLR1, m_preflr1);
	DDX_Text(pDX, IDC_PREFLR2, m_preflr2);
	DDX_Text(pDX, IDC_PREFLR3, m_preflr3);
	DDX_Text(pDX, IDC_EDITACC, m_acc);
	DDX_Text(pDX, IDC_TOTAL1, m_Total1);
	DDX_Text(pDX, IDC_TOTAL2, m_Total2);
	DDX_Text(pDX, IDC_TOTAL3, m_Total3);
	DDX_Text(pDX, IDC_EDITMASS, m_mass);
}

BEGIN_MESSAGE_MAP(CDialogmain, CDialogEx)
ON_BN_CLICKED(IDC_START, &CDialogmain::OnClickedStart)
ON_BN_CLICKED(IDOK, &CDialogmain::OnBnClickedOk)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_ACC2, &CDialogmain::OnBnClickedAcc2)
ON_BN_CLICKED(IDC_ACC10, &CDialogmain::OnBnClickedAcc10)
ON_BN_CLICKED(IDC_ACC20, &CDialogmain::OnBnClickedAcc20)
ON_BN_CLICKED(IDC_ACC50, &CDialogmain::OnBnClickedAcc50)
ON_BN_CLICKED(IDC_BUTTONPAUSE, &CDialogmain::OnBnClickedButtonpause)
ON_BN_CLICKED(IDC_BUTTONCONTINUE, &CDialogmain::OnBnClickedButtoncontinue)
ON_BN_CLICKED(IDC_BUTTONREPAIR1, &CDialogmain::OnBnClickedButtonrepair1)
ON_BN_CLICKED(IDC_BUTTONREPAIR2, &CDialogmain::OnBnClickedButtonrepair2)
ON_BN_CLICKED(IDC_BUTTONREPAIR3, &CDialogmain::OnBnClickedButtonrepair3)
ON_WM_PAINT()
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// CDialogmain 消息处理程序
Elevator<People> *e[N];
void CDialogmain::OnClickedStart() //程序启动函数；此后所有运算都在此后运行
{
	//一些初始化工作在此函数内完成
	// TODO: 在此添加控件通知处理程序代码
	//计时器设定，执行此语句后，跳入OnTimer函数中
	Ini(e);
	int i;
	for (i = 0; i < L + 1; i++)
	{
		n[i] = 0;
	}
	Refresh(e);
	SetTimer(1, 1000 / v, NULL);
	//计时器设定，执行此语句后，跳入OnTimer函数中
}

void CDialogmain::OnBnClickedOk() //点击结束按钮时执行的操作放入此函数中
{
	// TODO: 在此添加控件通知处理程序代码
	exit(1);
}

void CDialogmain::OnTimer(UINT_PTR nIDEvent) //计时器函数，主要部分。。。
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Refresh(e);
	SetPeople();
	Show(n);
	for (int i = 0; i < N; i++)
	{
		e[i]->Change();
		e[i]->Continue();
		CEdit *p;
		switch (e[i]->num)
		{
		case 0:
			p = &m_EditCondition1;
			break;
		case 1:
			p = &m_EditCondition2;
			break;
		case 2:
			p = &m_EditCondition3;
			break;
		}
		if (e[i]->Direction() == UP)
		{
			p->SetWindowText(L"上升中");
		}
		else if (e[i]->Direction() == DOWN)
		{
			p->SetWindowText(L"下降中");
		}
		else if (e[i]->condition)
		{
			p->SetWindowText(L"上下客中");
		}
		else
		{
			p->SetWindowText(L"停止");
		}
		if (e[i]->presflr != m_PreFlr[i])
		{
			switch (e[i]->num)
			{
			case 0:
			{
				m_PrEle1.SetPos(int(e[i]->presflr));
				break;
			}
			case 1:
			{
				m_PrEle2.SetPos(int(e[i]->presflr));
				break;
			}
			case 2:
			{
				m_PrEle3.SetPos(int(e[i]->presflr));
				break;
			}
			}
		}

		m_PreFlr[i] = e[i]->presflr;
		SetTime(e[i]->num, (int)e[i]->time);
		SetPreflr(e[i]->num, (int)e[i]->presflr);
		SetObjflr(e[i]->num, e[i]->objflr);
		SetWeight(e[i]->num, e[i]->total);
		CheckTime(e[i]->num, (int)e[i]->time);
	}
	SetAcc(NULL, v);
	SetMass();

	CDialogEx::OnTimer(nIDEvent);
}

BOOL CDialogmain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//{ WM_PAINT, 0, 0, 0, AfxSig_vv,	(AFX_PMSG)(AFX_PMSGW)(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > ( &CDialogmain :: OnPaint)) ;}
	//{ WM_CTLCOLOR, 0, 0, 0, AfxSig_hDWw, (AFX_PMSG)(AFX_PMSGW) (static_cast< HBRUSH (AFX_MSG_CALL CWnd::*)(CDC*, CWnd*, UINT)>  ( &CDialogmain :: OnCtlColor)) ;}
	// TODO:  在此添加额外的初始化
	m_PrEle1.SetRange(0, 20);
	m_PrEle2.SetRange(0, 20);
	m_PrEle3.SetRange(0, 20);
	m_PrEle1.SetStep(1);
	m_PrEle2.SetStep(1);
	m_PrEle3.SetStep(1);
	m_PrEle1.SetPos(1);
	m_PrEle2.SetPos(10);
	m_PrEle3.SetPos(20); //初始化电梯进度条的状态，一号电梯最底端，二号中端，三号顶端

	return TRUE;
	// return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDialogmain::SetPeople(void) //显示人分布的函数
{
	int num = 0;
	m_Flrnum1 = n[1];
	m_Flrnum2 = n[2];
	m_Flrnum3 = n[3];
	m_Flrnum4 = n[4];
	m_Flrnum5 = n[5];
	m_Flrnum6 = n[6];
	m_Flrnum7 = n[7];
	m_Flrnum8 = n[8];
	m_Flrnum9 = n[9];
	m_Flrnum10 = n[10];
	m_Flrnum11 = n[11];
	m_Flrnum12 = n[12];
	m_Flrnum13 = n[13];
	m_Flrnum14 = n[14];
	m_Flrnum15 = n[15];
	m_Flrnum16 = n[16];
	m_Flrnum17 = n[17];
	m_Flrnum18 = n[18];
	m_Flrnum19 = n[19];
	m_Flrnum20 = n[20];
	for (int i = 1; i <= 20; i++)
	{
		num += n[i];
	}

	SetTransNum(num);
	UpdateData(FALSE);
}

void CDialogmain::SetTime(int num, int time) //显示时间函数
{
	if (num == 0)
		m_time1 = time;
	if (num == 1)
		m_time2 = time;
	if (num == 2)
		m_time3 = time;
	UpdateData(FALSE);
}

int CDialogmain::SetTransNum(int transportnum) //已运人数函数
{
	m_Transnum = transportnum;
	UpdateData(FALSE);
	return 0;
}

void CDialogmain::OnBnClickedAcc2()
{
	// TODO: 在此添加控件通知处理程序代码
	v = 2;
}

void CDialogmain::OnBnClickedAcc10()
{
	// TODO: 在此添加控件通知处理程序代码
	v = 10;
}

void CDialogmain::OnBnClickedAcc20()
{
	// TODO: 在此添加控件通知处理程序代码
	v = 20;
}

void CDialogmain::OnBnClickedAcc50()
{
	// TODO: 在此添加控件通知处理程序代码
	v = 50;
}

void CDialogmain::OnBnClickedButtonpause()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);
}

void CDialogmain::OnBnClickedButtoncontinue()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(1, 1000 / v, NULL);
}

void CDialogmain::SetObjflr(int num, int objflr)
{
	switch (num)
	{
	case 0:
	{
		m_objflr1 = objflr;
		break;
	}
	case 1:
	{
		m_objflr2 = objflr;
		break;
	}
	case 2:
	{
		m_objflr3 = objflr;
		break;
	}
	}
	UpdateData(FALSE);
}

void CDialogmain::SetPreflr(int num, int preflr)
{
	switch (num)
	{
	case 0:
	{
		m_preflr1 = preflr;
		break;
	}
	case 1:
	{
		m_preflr2 = preflr;
		break;
	}
	case 2:
	{
		m_preflr3 = preflr;
		break;
	}
	}
	UpdateData(FALSE);
}

void CDialogmain::SetAcc(int num, int Acc)
{
	m_acc = v;
	UpdateData(FALSE);
}

void CDialogmain::SetWeight(int num, int total)
{
	switch (num)
	{
	case 0:
	{
		m_Total1 = total;
		break;
	}
	case 1:
	{
		m_Total2 = total;
		break;
	}
	case 2:
	{
		m_Total3 = total;
		break;
	}
	}
	UpdateData(FALSE);
}

void CDialogmain::CheckTime(int num, int time)
{
	if (time == 1000)
	{
		switch (num)
		{
		case 0:
		{
			Beep(800, 2000);
			MessageBox(L"一号电梯达到阈值");
			break;
		}
		case 1:
		{
			Beep(800, 2000);
			MessageBox(L"二号电梯达到阈值");
			break;
		}
		case 2:
		{
			Beep(800, 2000);
			MessageBox(L"三号电梯达到阈值");
			break;
		}
		}
	}
}

void CDialogmain::OnBnClickedButtonrepair1()
{
	// TODO: 在此添加控件通知处理程序代码
	e[0]->Repair();
}

void CDialogmain::OnBnClickedButtonrepair2()
{
	// TODO: 在此添加控件通知处理程序代码
	e[1]->Repair();
}

void CDialogmain::OnBnClickedButtonrepair3()
{
	// TODO: 在此添加控件通知处理程序代码
	e[2]->Repair();
}

void CDialogmain::SetMass(void)
{
	m_mass = mass;
	UpdateData(FALSE);
}


void CDialogmain::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	CRect  rect;  
	GetClientRect(&rect);  
	CDC  dcMem;   //定义一个工具箱（设备上下文）
	dcMem.CreateCompatibleDC(&dc);///建立关联DC 
	CBitmap  bmpBackground;   //位图对象
	bmpBackground.LoadBitmap(IDB_BITMAP3);   //IDB_BITMAP是你自己的图对应的ID  
	BITMAP  bitmap;  
	bmpBackground.GetBitmap(&bitmap);  //建立绑定关系
	CBitmap  *pbmpOld=dcMem.SelectObject(&bmpBackground);   //保存原有CDC对象，并选入新CDC对象入DC
	dc.SetStretchBltMode(COLORONCOLOR);//防止bmp图片失真
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,  bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);

	// （个人建议把,rect.Width(),rect.Height()这两个数据 换成你的图片的大小，前提是图片足够大，这样图片不容易失真。关于图片失真，参考：http://blog.csdn.net/abidepan/article/details/7963929 ）
	dcMem.SelectObject(pbmpOld);
	bmpBackground.DeleteObject();
	dcMem.DeleteDC();

	// 不为绘图消息调用 CDialogEx::OnPaint()
}

/*
HBRUSH CDialogmain::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  在此更改 DC 的任何特性

	if (nCtlColor == CTLCOLOR_EDIT)
	{
		pDC->SetBkMode(TRANSPARENT);   //设置背景透明
		pDC->SetTextColor(RGB(0,0,255));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}else if( nCtlColor == CTLCOLOR_STATIC)      
	{    
		pDC->SetBkMode(TRANSPARENT);   //设置背景透明 
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
*/