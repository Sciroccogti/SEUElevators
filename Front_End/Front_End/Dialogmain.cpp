// Dialogmain.cpp : 实现文件
//

#include "stdafx.h"
#include "Front_End.h"
#include "Dialogmain.h"
#include "afxdialogex.h"
#include "People.h"

// CDialogmain 对话框
int n[L + 1];
IMPLEMENT_DYNAMIC(CDialogmain, CDialogEx)

CDialogmain::CDialogmain(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogmain::IDD, pParent)
	, Vtime(0)
	, v(1)
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
	for(int i=0;i<3;i++)
	{
		m_PreFlr[i]=0;
		m_PreFrontFlr[i]=0;
	}
	m_objflr1 = 0;
	m_objflr2 = 0;
	m_objflr3 = 0;
	//  m_preflr1 = 0;
	//  m_preflr2 = 0;
	//  m_preflr3 = 0;
	m_preflr1 = 0.0;
	m_preflr2 = 0.0;
	m_preflr3 = 0.0;
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
	DDX_Control(pDX, IDC_ELE1, m_PrEle1);
	DDX_Control(pDX, IDC_ELE2, m_PrEle2);
	DDX_Control(pDX, IDC_ELE3, m_PrEle3);
	//  DDX_Control(pDX, IDC_TIME1, m_time1);
	DDX_Text(pDX, IDC_TIME1, m_time1);
	DDX_Text(pDX, IDC_TIME3, m_time3);
	DDX_Text(pDX, IDC_EDIT2, m_time2);
	DDX_Text(pDX, IDC_OBJFLR1, m_objflr1);
	DDX_Text(pDX, IDC_OBJFLR2, m_objflr2);
	DDX_Text(pDX, IDC_OBJFLR3, m_objflr3);
	//  DDX_Text(pDX, IDC_PREFLR1, m_preflr1);
	//  DDX_Text(pDX, IDC_PREFLR2, m_preflr2);
	//  DDX_Text(pDX, IDC_PREFLR3, m_preflr3);
	DDX_Text(pDX, IDC_PREFLR1, m_preflr1);
	DDX_Text(pDX, IDC_PREFLR2, m_preflr2);
	DDX_Text(pDX, IDC_PREFLR3, m_preflr3);
}


BEGIN_MESSAGE_MAP(CDialogmain, CDialogEx)
	ON_BN_CLICKED(IDC_START, &CDialogmain::OnClickedStart)
	ON_BN_CLICKED(IDOK, &CDialogmain::OnBnClickedOk)
	ON_WM_TIMER()
//	ON_EN_CHANGE(IDC_EDIT2, &CDialogmain::OnEnChangeEdit2)
ON_BN_CLICKED(IDC_ACC2, &CDialogmain::OnBnClickedAcc2)
ON_BN_CLICKED(IDC_ACC10, &CDialogmain::OnBnClickedAcc10)
ON_BN_CLICKED(IDC_ACC20, &CDialogmain::OnBnClickedAcc20)
ON_BN_CLICKED(IDC_ACC50, &CDialogmain::OnBnClickedAcc50)
ON_BN_CLICKED(IDC_BUTTONPAUSE, &CDialogmain::OnBnClickedButtonpause)
ON_BN_CLICKED(IDC_BUTTONCONTINUE, &CDialogmain::OnBnClickedButtoncontinue)
END_MESSAGE_MAP()


// CDialogmain 消息处理程序

/******************************************************************************************/
Elevator <People> *e[N];
void CDialogmain::OnClickedStart()            //程序启动函数；此后所有运算都在此后运行
	//一些初始化工作在此函数内完成
{
	// TODO: 在此添加控件通知处理程序代码
              //计时器设定，执行此语句后，跳入OnTimer函数中
	Ini(e);
	int i;
	for(i = 0; i < L + 1; i++){
		n[i] = 0;
	}
		Refresh(e);
	SetTimer(1,1000/v,NULL);
	//计时器设定，执行此语句后，跳入OnTimer函数中

	//以下为测试代码


}


void CDialogmain::OnBnClickedOk()	//点击结束按钮时执行的操作放入此函数中
{
	// TODO: 在此添加控件通知处理程序代码
	//KillTimer(1);
	CDialogEx::OnOK();
}


void CDialogmain::OnTimer(UINT_PTR nIDEvent)  //计时器函数，主要部分。。。
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Refresh(e);
	SetPeople();
	Show(n);
	for(int i = 0; i < N; i++){
		e[i]->Change();
		e[i]->Continue();
		//if(int(e[i]->presflr)>int(m_PreFlr[i]))
			//MoveUp(e[i]->num);
		//if(int(e[i]->presflr)<int(m_PreFlr[i]))
			//MoveDown(e[i]->num);
		CEdit *p;
		switch(e[i]->num)
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
		if(e[i]->Direction() == UP){
			p->SetWindowText(L"上升中");
		}else if(e[i]->Direction() == DOWN){
			p->SetWindowText(L"下降中");
		}else if(e[i]->condition){
			p->SetWindowText(L"上下客中");
		}else {
			p->SetWindowText(L"停止");
		}
		if(e[i]->presflr!=m_PreFlr[i])
		{
			switch(e[i]->num)
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
		
		m_PreFlr[i]=e[i]->presflr;
		SetTime(e[i]->num,e[i]->time);
		SetPreflr(e[i]->num,e[i]->presflr);
		SetObjflr(e[i]->num,e[i]->objflr);
	}
	
	CDialogEx::OnTimer(nIDEvent);
}


//void CDialogmain::MoveUp(int num)//向上一层的函数，电梯后端状态为上升时，每三秒执行一次该函数
//	//该函数可自动同步电梯前端显示状态，参数num是电梯的编号（后面的num都指电梯编号）
//{
//	if(num==0)
//	{
//		int nPos=m_PrEle1.GetPos();
//		int nLow,nUp;
//		m_PrEle1.GetRange(nLow,nUp);
//		nPos++;
//		if(nPos>nUp)
//		{	
//			nPos=nUp;
//			m_EditCondition1.SetWindowText(L"停止");
//		}else{
//		m_EditCondition1.SetWindowText(L"上升中");
//		}
//		m_PrEle1.SetPos(nPos);
//	}
//	if(num==1)
//	{
//		int nPos=m_PrEle2.GetPos();
//		int nLow,nUp;
//		m_PrEle2.GetRange(nLow,nUp);
//		nPos++;
//		if(nPos>nUp)
//		{	
//			nPos=nUp;
//			m_EditCondition2.SetWindowText(L"停止");
//		}else{
//		m_EditCondition2.SetWindowText(L"上升中");
//		}
//		m_PrEle2.SetPos(nPos);
//
//	}
//	if(num==2)
//	{
//		int nPos=m_PrEle3.GetPos();
//		int nLow,nUp;
//		m_PrEle3.GetRange(nLow,nUp);
//		nPos++;
//		if(nPos>nUp)
//		{	
//			nPos=nUp;
//			m_EditCondition3.SetWindowText(L"停止");
//		}else{
//		m_EditCondition3.SetWindowText(L"上升中");
//		}
//		m_PrEle3.SetPos(nPos);
//	}
//}


BOOL CDialogmain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_PrEle1.SetRange(0,20);
	m_PrEle2.SetRange(0,20);
	m_PrEle3.SetRange(0,20);
	m_PrEle1.SetStep(1);
	m_PrEle2.SetStep(1);
	m_PrEle3.SetStep(1);
	m_PrEle1.SetPos(1);
	m_PrEle2.SetPos(10);
	m_PrEle3.SetPos(20);			//初始化电梯进度条的状态，一号电梯最底端，二号中端，三号顶端

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


//void CDialogmain::MoveDown(int num)//电梯向下的函数，说明同MoveUp
//{
//	if(num==0)
//	{
//		int nPos=m_PrEle1.GetPos();
//		int nLow,nUp;
//		m_PrEle1.GetRange(nLow,nUp);
//		nPos--;
//		if(nPos<=nLow)
//		{
//			nPos=nLow+1;
//			m_EditCondition1.SetWindowText(L"停止");
//		}
//		else{
//		m_EditCondition1.SetWindowText(L"下降中");
//		}
//		m_PrEle1.SetPos(nPos);
//	}
//	if(num==1)
//	{
//		int nPos=m_PrEle2.GetPos();
//		int nLow,nUp;
//		m_PrEle2.GetRange(nLow,nUp);
//		nPos--;
//		if(nPos<=nLow)
//		{
//			nPos=nLow+1;
//			m_EditCondition2.SetWindowText(L"停止");
//		}
//		else{
//		m_EditCondition2.SetWindowText(L"下降中");
//		}
//		m_PrEle2.SetPos(nPos);
//	}
//	if(num==2)
//	{
//		int nPos=m_PrEle3.GetPos();
//		int nLow,nUp;
//		m_PrEle3.GetRange(nLow,nUp);
//		nPos--;
//		if(nPos<=nLow)
//		{
//			nPos=nLow+1;
//			m_EditCondition3.SetWindowText(L"停止");
//		}
//		else{
//		m_EditCondition3.SetWindowText(L"下降中");
//		}
//		m_PrEle3.SetPos(nPos);
//	}
//}


//void CDialogmain::Stop(int num)//电梯停止函数
//{
//	if(num==0)
//		m_EditCondition1.SetWindowText(L"停止");
//	if(num==1)
//		m_EditCondition2.SetWindowText(L"停止");
//	if(num==2)
//		m_EditCondition3.SetWindowText(L"停止");
//}




//void CDialogmain::Loading(int num)//上下客的函数，使用前需更新人员分布
//{
//	if(num==0)
//		{
//			m_EditCondition1.SetWindowText(L"上下客中");
//			SetPeople();
//		}
//	if(num==1)
//		{
//			m_EditCondition2.SetWindowText(L"上下客中");
//			SetPeople();
//		}
//	if(num==2)
//		{
//			m_EditCondition3.SetWindowText(L"上下客中");
//			SetPeople();
//		}
//}


void CDialogmain::SetPeople(void)//显示人分布的函数
{
	int num =0; 
	m_Flrnum1=n[1];
	m_Flrnum2=n[2];
	m_Flrnum3=n[3];
	m_Flrnum4=n[4];
	m_Flrnum5=n[5];
	m_Flrnum6=n[6];
	m_Flrnum7=n[7];
	m_Flrnum8=n[8];
	m_Flrnum9=n[9];
	m_Flrnum10=n[10];
	m_Flrnum11=n[11];
	m_Flrnum12=n[12];
	m_Flrnum13=n[13];
	m_Flrnum14=n[14];
	m_Flrnum15=n[15];
	m_Flrnum16=n[16];
	m_Flrnum17=n[17];
	m_Flrnum18=n[18];
	m_Flrnum19=n[19];
	m_Flrnum20=n[20];
	for(int i=1;i<=20;i++)
	{
		num+=n[i];
	}
	
	SetTransNum(num);
	UpdateData(FALSE);
}

/*
void CDialogmain::Connection(int* ptemp)//将人员分布数组联入前端，最开始进行
{
	p=ptemp;
}
*/

//void CDialogmain::OnEnChangeEdit2()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}


//void CDialogmain::SetTime(int num)
//{
//	
//}


void CDialogmain::SetTime(int num, int time)//显示时间函数
{
	if(num==0)
		m_time1=time;
	if(num==1)
		m_time2=time;
	if(num==2)
		m_time3=time;
	UpdateData(FALSE);
}


//int CDialogmain::GetRefreshNum(void)//得到刷新人数的函数，人数是唯一的输入型变量
//									//需在开始进行
//{
//	UpdateData(TRUE);
//	return m_Refreshnum;
//}



int CDialogmain::SetTransNum(int transportnum)//已运人数函数
{
	m_Transnum=transportnum;
	UpdateData(FALSE);
	return 0;
}


//void CDialogmain::ResetCondition(int num)
//{
//
//}


//void CDialogmain::ResetConditionDown(int num)
//{
//	if(num==0)
//		m_EditCondition1.SetWindowText(L"下降中");
//	if(num==1)
//		m_EditCondition2.SetWindowText(L"下降中");
//	if(num==2)
//		m_EditCondition3.SetWindowText(L"下降中");
//}


//void CDialogmain::ResetConditionUp(int num)
//{
//	if(num==0)
//		m_EditCondition1.SetWindowText(L"上升中");
//	if(num==1)
//		m_EditCondition2.SetWindowText(L"上升中");
//	if(num==2)
//		m_EditCondition3.SetWindowText(L"上升中");
//}


void CDialogmain::OnBnClickedAcc2()
{
	// TODO: 在此添加控件通知处理程序代码
	v=2;
}


void CDialogmain::OnBnClickedAcc10()
{
	// TODO: 在此添加控件通知处理程序代码
	v=10;
}


void CDialogmain::OnBnClickedAcc20()
{
	// TODO: 在此添加控件通知处理程序代码
	v=20;
}


void CDialogmain::OnBnClickedAcc50()
{
	// TODO: 在此添加控件通知处理程序代码
	v=50;
}


void CDialogmain::OnBnClickedButtonpause()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);
}


void CDialogmain::OnBnClickedButtoncontinue()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(1,1000/v,NULL);
}


void CDialogmain::SetObjflr(int num, int objflr)
{
	switch(num)
	{
	case 0:
		{
			m_objflr1=objflr;
			break;
		}
	case 1:
		{
			m_objflr2=objflr;
			break;
		}
	case 2:
		{
			m_objflr3=objflr;
			break;
		}
	}
	UpdateData(FALSE);
}




void CDialogmain::SetPreflr(int num, double preflr)
{
	switch(num)
	{
	case 0:
		{
			m_preflr1=preflr;
			break;
		}
	case 1:
		{
			m_preflr2=preflr;
			break;
		}
	case 2:
		{
			m_preflr3=preflr;
			break;
		}
	}
	UpdateData(FALSE);
}
