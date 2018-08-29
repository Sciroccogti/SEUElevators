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
	, Vtime(0)
	//, keytime(0)
	//, countime(0)
	, keytime1(0)
	, keytime2(0)
	, keytime3(0)
	//, countime(0)
	, countime1(0)
	, countime2(0)
	, countime3(0)
	, m_time1(0)
	, p(NULL)
{

	//  m_Flrnum1 = 0;
	//  m_Flrnum10 = 0;
	//  m_Flrnum11 = 0;
	//  m_Flrnum12 = 0;
	//  m_Flrnum13 = 0;
	//  m_Flrnum14 = 0;
	//  m_Flrnum15 = 0;
	//  m_Flrnum16 = 0;
	//  m_Flrnum17 = 0;
	//  m_Flrnum18 = 0;
	//  m_Flrnum19 = 0;
	//  m_Flrnum2 = 0;
	//  m_Flrnum20 = 0;
	//  m_Flrnum3 = 0;
	//  m_Flrnum4 = 0;
	//  m_Flrnum5 = 0;
	//  m_Flrnum6 = 0;
	//  m_Flrnum7 = 0;
	//  m_Flrnum8 = 0;
	//  m_Flrnum9 = 0;
	m_Refreshnum = 0;
	m_Transnum = 0;
	//  m_Time = _T("");
	m_time1 = 0;
	m_time2 = 0;
	m_time3 = 0;
	m_flrnum1 = 0;
	m_flrnum10 = 0;
	m_flrnum11 = 0;
	m_flrnum12 = 0;
	m_flrnum13 = 0;
	m_flrnum14 = 0;
	m_flrnum15 = 0;
	m_flrnum16 = 0;
	m_flrnum17 = 0;
	m_flrnum18 = 0;
	m_flrnum19 = 0;
	m_flrnum2 = 0;
	m_flrnum20 = 0;
	m_flrnum3 = 0;
	m_flrnum4 = 0;
	m_flrnum5 = 0;
	m_flrnum6 = 0;
	m_flrnum7 = 0;
	m_flrnum8 = 0;
	m_flrnum9 = 0;
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
	//  DDX_Text(pDX, IDC_FLRNUM1, m_Flrnum1);
	//  DDX_Text(pDX, IDC_FLRNUM10, m_Flrnum10);
	//  DDX_Text(pDX, IDC_FLRNUM11, m_Flrnum11);
	//  DDX_Text(pDX, IDC_FLRNUM12, m_Flrnum12);
	//  DDX_Text(pDX, IDC_FLRNUM13, m_Flrnum13);
	//  DDX_Text(pDX, IDC_FLRNUM14, m_Flrnum14);
	//  DDX_Text(pDX, IDC_FLRNUM15, m_Flrnum15);
	//  DDX_Text(pDX, IDC_FLRNUM16, m_Flrnum16);
	//  DDX_Text(pDX, IDC_FLRNUM17, m_Flrnum17);
	//  DDX_Text(pDX, IDC_FLRNUM18, m_Flrnum18);
	//  DDX_Text(pDX, IDC_FLRNUM19, m_Flrnum19);
	//  DDX_Text(pDX, IDC_FLRNUM2, m_Flrnum2);
	//  DDX_Text(pDX, IDC_FLRNUM20, m_Flrnum20);
	//  DDX_Text(pDX, IDC_FLRNUM3, m_Flrnum3);
	//  DDX_Text(pDX, IDC_FLRNUM4, m_Flrnum4);
	//  DDX_Text(pDX, IDC_FLRNUM5, m_Flrnum5);
	//  DDX_Text(pDX, IDC_FLRNUM6, m_Flrnum6);
	//  DDX_Text(pDX, IDC_FLRNUM7, m_Flrnum7);
	//  DDX_Text(pDX, IDC_FLRNUM8, m_Flrnum8);
	//  DDX_Text(pDX, IDC_FLRNUM9, m_Flrnum9);
	DDX_Text(pDX, IDC_REFRESH, m_Refreshnum);
	DDX_Text(pDX, IDC_TRANS, m_Transnum);
	DDX_Control(pDX, IDC_ELE1, m_Progress_ele1);
	DDX_Control(pDX, IDC_ELE2, m_Progress_ele2);
	DDX_Control(pDX, IDC_ELE3, m_Progress_ele3);
	//  DDX_Text(pDX, IDC_EDITTIME, m_Time);
	DDX_Text(pDX, IDC_EDITTIME1, m_time1);
	DDX_Text(pDX, IDC_EDITTIME2, m_time2);
	DDX_Text(pDX, IDC_EDITTIME3, m_time3);
	DDX_Text(pDX, IDC_EDITF1, m_flrnum1);
	DDX_Text(pDX, IDC_EDITF10, m_flrnum10);
	DDX_Text(pDX, IDC_EDITF11, m_flrnum11);
	DDX_Text(pDX, IDC_EDITF12, m_flrnum12);
	DDX_Text(pDX, IDC_EDITF13, m_flrnum13);
	DDX_Text(pDX, IDC_EDITF14, m_flrnum14);
	DDX_Text(pDX, IDC_EDITF15, m_flrnum15);
	DDX_Text(pDX, IDC_EDITF16, m_flrnum16);
	DDX_Text(pDX, IDC_EDITF17, m_flrnum17);
	DDX_Text(pDX, IDC_EDITF18, m_flrnum18);
	DDX_Text(pDX, IDC_EDITF19, m_flrnum19);
	DDX_Text(pDX, IDC_EDITF2, m_flrnum2);
	DDX_Text(pDX, IDC_EDITF20, m_flrnum20);
	DDX_Text(pDX, IDC_EDITF3, m_flrnum3);
	DDX_Text(pDX, IDC_EDITF4, m_flrnum4);
	DDX_Text(pDX, IDC_EDITF5, m_flrnum5);
	DDX_Text(pDX, IDC_EDITF6, m_flrnum6);
	DDX_Text(pDX, IDC_EDITF7, m_flrnum7);
	DDX_Text(pDX, IDC_EDITF8, m_flrnum8);
	DDX_Text(pDX, IDC_EDITF9, m_flrnum9);
}


BEGIN_MESSAGE_MAP(CDialogmain, CDialogEx)
	ON_BN_CLICKED(IDC_START, &CDialogmain::OnClickedStart)
	ON_BN_CLICKED(IDOK, &CDialogmain::OnBnClickedOk)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDITF20, &CDialogmain::OnEnChangeEditf20)
END_MESSAGE_MAP()


// CDialogmain 消息处理程序

/******************************************************************************************/
void CDialogmain::OnClickedStart()            /////程序启动函数；此后所有运算都在此后运行
{
	// TODO: 在此添加控件通知处理程序代码


	int a[20];
	for(int i=0;i<20;i++)
		a[i]=i;
	//p=a;
	Connect(a);
	//SetPeople();
	//SetPeople();*/



	SetEleMotion(1,1,5);
	SetEleMotion(2,-1,4);
	SetEleMotion(3,-1,10);
	for(int i=0;i<20;i++)
		a[i]=1;
	SetEleMotion(1,2,3);
	for(int i=0;i<20;i++)
		a[i]=2;
	SetEleMotion(2,2,4);
	for(int i=0;i<20;i++)
		a[i]=3;
	SetEleMotion(3,-2,8);
	m_EditCondition1.SetWindowText(L"UP");
}


void CDialogmain::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CDialogmain::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent<=3)
	{	
		keytime1++;
		switch(nIDEvent)
		{
		case 1:
			{
				//UpdatePos();
				UpdateTime(1);
				m_EditCondition1.SetWindowText(L"上下客中");
				SetPeople();
				break;
			}
		case 2:
			{
				int nPos=m_Progress_ele1.GetPos();
				int nLow,nUp;
				m_Progress_ele1.GetRange(nLow,nUp);
				nPos++;
				if(nPos>nUp)
					nPos=nUp;
				m_Progress_ele1.SetPos(nPos);
				//UpdatePos();
				UpdateTime(1);
				m_EditCondition1.SetWindowText(L"上升中");
				break;
			}
		case 3:
			{
				int nPos=m_Progress_ele1.GetPos();
				int nLow,nUp;
				m_Progress_ele1.GetRange(nLow,nUp);
				nPos--;
				if(nPos<=nLow)
				{
					nPos=nLow+1;
				}
				m_Progress_ele1.SetPos(nPos);
				//UpdatePos();
				UpdateTime(1);
				m_EditCondition1.SetWindowText(L"下降中");
				break;
			}
		}
		if(keytime1>=countime1)
		{
			KillTimer(nIDEvent);
			keytime1=0;
			m_EditCondition1.SetWindowText(L"停止");
		}
	}

	if(nIDEvent>3&&nIDEvent<=6)
	{	
		keytime2++;
		switch(nIDEvent)
		{
		case 4:
			{
				//UpdatePos();
				UpdateTime(2);
				m_EditCondition2.SetWindowText(L"上下客中");
				SetPeople();
				break;
			}
		case 5:
			{
				int nPos=m_Progress_ele2.GetPos();
				int nLow,nUp;
				m_Progress_ele2.GetRange(nLow,nUp);
				nPos++;
				if(nPos>nUp)
					nPos=nUp;
				m_Progress_ele2.SetPos(nPos);
				//UpdatePos();
				UpdateTime(2);
				m_EditCondition2.SetWindowText(L"上升中");
				break;
			}
		case 6:
			{
				int nPos=m_Progress_ele2.GetPos();
				int nLow,nUp;
				m_Progress_ele2.GetRange(nLow,nUp);
				nPos--;
				if(nPos<=nLow)
				{
					nPos=nLow+1;
				}
				m_Progress_ele2.SetPos(nPos);
				//UpdatePos();
				UpdateTime(2);
				m_EditCondition2.SetWindowText(L"下降中");
				break;
			}
		}
		if(keytime2>=countime2)
		{
			KillTimer(nIDEvent);
			keytime2=0;
			m_EditCondition2.SetWindowText(L"停止");
		}
	}

	if(nIDEvent>6)
	{	
		keytime3++;
		switch(nIDEvent)
		{
		case 7:
			{
				//UpdatePos();
				UpdateTime(3);
				m_EditCondition3.SetWindowText(L"上下客中");
				SetPeople();
				break;
			}
		case 8:
			{
				int nPos=m_Progress_ele3.GetPos();
				int nLow,nUp;
				m_Progress_ele3.GetRange(nLow,nUp);
				nPos++;
				if(nPos>nUp)
					nPos=nUp;
				m_Progress_ele3.SetPos(nPos);
				//UpdatePos();
				UpdateTime(3);
				m_EditCondition3.SetWindowText(L"上升中");
				break;
			}
		case 9:
			{
				int nPos=m_Progress_ele3.GetPos();
				int nLow,nUp;
				m_Progress_ele3.GetRange(nLow,nUp);
				nPos--;
				if(nPos<=nLow)
				{
					nPos=nLow+1;
				}
				m_Progress_ele3.SetPos(nPos);
				//UpdatePos();
				UpdateTime(3);
				m_EditCondition3.SetWindowText(L"下降中");
				break;
			}
		}
		if(keytime3>=countime3)
		{
			KillTimer(nIDEvent);
			keytime3=0;
			m_EditCondition3.SetWindowText(L"停止");
		}
	}

	

	CDialogEx::OnTimer(nIDEvent);
	//CDialogEx::OnTimer(nIDEvent);
}


BOOL CDialogmain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Progress_ele1.SetRange(0,20);
	m_Progress_ele2.SetRange(0,20);
	m_Progress_ele3.SetRange(0,20);
	m_Progress_ele1.SetStep(1);
	m_Progress_ele2.SetStep(1);
	m_Progress_ele3.SetStep(1);
	m_Progress_ele1.SetPos(1);
	m_Progress_ele2.SetPos(10);
	m_Progress_ele3.SetPos(20);




	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDialogmain::SetEleMotion(int num, int mode, int vtime)
{
	if(num==1)
	{
		countime1=vtime;
		switch(mode)
		{
			case 0:
			{
				//UpdateCondition(0);
				//SetTimer(1,1000,NULL);
				break;
			}
			case 2:
			{
				//UpdateCondition(2);
				SetTimer(1,1000,NULL);
				break;
			}
			case -2: 
			{	//UpdateCondition(-2);
				SetTimer(1,1000,NULL);
				break;
			}
			case 1:
			{
				//UpdateCondition(1);
				SetTimer(2,1000,NULL);
				break;
			}
			case -1: 
			{	
				//UpdateCondition(-1);
				SetTimer(3,1000,NULL);
				break;
			}
			default:
				break;
		}
	}
	if(num==2)
	{
		countime2=vtime;
		switch(mode)
		{
			case 0:
			{
				//UpdateCondition(0);
				//SetTimer(4,1000,NULL);
				break;
			}
			case 2:
			{
				//UpdateCondition(2);
				SetTimer(4,1000,NULL);
				break;
			}
			case -2: 
			{	//UpdateCondition(-2);
				SetTimer(4,1000,NULL);
				break;
			}
			case 1:
			{
				//UpdateCondition(1);
				SetTimer(5,1000,NULL);
				break;
			}
			case -1: 
			{	
				//UpdateCondition(-1);
				SetTimer(6,1000,NULL);
				break;
			}
			default:
				break;
		}
	}
	if(num==3)
	{
		countime3=vtime;
		switch(mode)
		{
			case 0:
			{
				//UpdateCondition(0);
				//SetTimer(7,1000,NULL);
				break;
			}
			case 2:
			{
				//UpdateCondition(2);
				SetTimer(7,1000,NULL);
				break;
			}
			case -2: 
			{	//UpdateCondition(-2);
				SetTimer(7,1000,NULL);
				break;
			}
			case 1:
			{
				//UpdateCondition(1);
				SetTimer(8,1000,NULL);
				break;
			}
			case -1: 
			{	
				//UpdateCondition(-1);
				SetTimer(9,1000,NULL);
				break;
			}
			default:
				break;
		}
	}
}



//void CDialogmain::UpdateTime(void)
//{
//	Vtime++;
//	m_Time.Format(L"%d",Vtime);
//	UpdateData(FALSE);
//}


void CDialogmain::UpdateTime(int num)
{
	if(num==1)
	{	
		m_time1++;
	}
	if(num==2)
	{
		m_time2++;
	}
	if(num==3)
	{
		m_time3++;
	}
	UpdateData(FALSE);
}


//void CDialogmain::UpdateCondition(int num, int mode)
//{
//	switch(mode)
//}


void CDialogmain::SetPeople(void)
{
	m_flrnum1=p[0];
	m_flrnum2=p[1];
	m_flrnum3=p[2];
	m_flrnum4=p[3];
	m_flrnum5=p[4];
	m_flrnum6=p[5];
	m_flrnum7=p[6];
	m_flrnum8=p[7];
	m_flrnum9=p[8];
	m_flrnum10=p[9];
	m_flrnum11=p[10];
	m_flrnum12=p[11];
	m_flrnum13=p[12];
	m_flrnum14=p[13];
	m_flrnum15=p[14];
	m_flrnum16=p[15];
	m_flrnum17=p[16];
	m_flrnum18=p[17];
	m_flrnum19=p[18];
	m_flrnum20=p[19];


	UpdateData(FALSE);

}


void CDialogmain::OnEnChangeEditf20()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDialogmain::Connect(int* ptemp)
{
	if(ptemp!=0)
		p=ptemp;
}
