// Dialogmain.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Temp1001.h"
#include "Dialogmain.h"
#include "afxdialogex.h"
#include "People.h"


// CDialogmain �Ի���

IMPLEMENT_DYNAMIC(CDialogmain, CDialogEx)

CDialogmain::CDialogmain(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogmain::IDD, pParent)
	, Vtime(0)
	, p(NULL)
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
}


BEGIN_MESSAGE_MAP(CDialogmain, CDialogEx)
	ON_BN_CLICKED(IDC_START, &CDialogmain::OnClickedStart)
	ON_BN_CLICKED(IDOK, &CDialogmain::OnBnClickedOk)
	ON_WM_TIMER()
//	ON_EN_CHANGE(IDC_EDIT2, &CDialogmain::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CDialogmain ��Ϣ��������

/******************************************************************************************/
void CDialogmain::OnClickedStart()            //���������������˺��������㶼�ڴ˺�����
	//һЩ��ʼ�������ڴ˺��������
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
              //��ʱ���趨��ִ�д���������OnTimer������
	Elevator <People> *e[N];
	Ini(e);
	int n[L + 1] = {0};

	SetTimer(1,1000,NULL);//��ʱ���趨��ִ�д���������OnTimer������


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//����Ϊ���Դ���
	/*MoveUp(1);
	MoveUp(1);
	MoveUp(1); 
	MoveDown(2);
	MoveDown(2);
	MoveDown(2);
	MoveDown(2);*/

	/*int a[20];
	for(int i=0;i<20;i++)
		a[i]=1;
	Connection(a);
	Loading(1);*/
	/*SetTime(1,35);
	SetTime(2,45);
	SetTime(3,43);*/
	//int i=GetRefreshNum();
	//SetTransNum(43);

}


void CDialogmain::OnBnClickedOk()	//���������ťʱִ�еĲ�������˺�����
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	CDialogEx::OnOK();
}


void CDialogmain::OnTimer(UINT_PTR nIDEvent)  //��ʱ����������Ҫ���֡�����
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	Refresh(e);
	for(i = 0; i < N; i++){
		e[i]->Change();
		e[i]->Continue();
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CDialogmain::MoveUp(int num)//����һ��ĺ��������ݺ��״̬Ϊ����ʱ��ÿ����ִ��һ�θú���
	//�ú������Զ�ͬ������ǰ����ʾ״̬������num�ǵ��ݵı�ţ������num��ָ���ݱ�ţ�
{
	if(num==1)
	{
		int nPos=m_PrEle1.GetPos();
		int nLow,nUp;
		m_PrEle1.GetRange(nLow,nUp);
		nPos++;
		if(nPos>nUp)
		{	
			nPos=nUp;
		}
		m_PrEle1.SetPos(nPos);
		m_EditCondition1.SetWindowText(L"������");
	}
	if(num==2)
	{
		int nPos=m_PrEle2.GetPos();
		int nLow,nUp;
		m_PrEle2.GetRange(nLow,nUp);
		nPos++;
		if(nPos>nUp)
		{	
			nPos=nUp;
		}
		m_PrEle2.SetPos(nPos);
		m_EditCondition2.SetWindowText(L"������");
	}
	if(num==3)
	{
		int nPos=m_PrEle3.GetPos();
		int nLow,nUp;
		m_PrEle3.GetRange(nLow,nUp);
		nPos++;
		if(nPos>nUp)
		{	
			nPos=nUp;
		}
		m_PrEle3.SetPos(nPos);
		m_EditCondition3.SetWindowText(L"������");
	}
}


BOOL CDialogmain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	m_PrEle1.SetRange(0,20);
	m_PrEle2.SetRange(0,20);
	m_PrEle3.SetRange(0,20);
	m_PrEle1.SetStep(1);
	m_PrEle2.SetStep(1);
	m_PrEle3.SetStep(1);
	m_PrEle1.SetPos(1);
	m_PrEle2.SetPos(10);
	m_PrEle3.SetPos(20);			//��ʼ�����ݽ�������״̬��һ�ŵ�����׶ˣ������жˣ����Ŷ���

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDialogmain::MoveDown(int num)//�������µĺ�����˵��ͬMoveUp
{
	if(num==1)
	{
		int nPos=m_PrEle1.GetPos();
		int nLow,nUp;
		m_PrEle1.GetRange(nLow,nUp);
		nPos--;
		if(nPos<=nLow)
		{
			nPos=nLow+1;
		}
		m_PrEle1.SetPos(nPos);
		m_EditCondition1.SetWindowText(L"�½���");
	}
	if(num==2)
	{
		int nPos=m_PrEle2.GetPos();
		int nLow,nUp;
		m_PrEle2.GetRange(nLow,nUp);
		nPos--;
		if(nPos<=nLow)
		{
			nPos=nLow+1;
		}
		m_PrEle2.SetPos(nPos);
		m_EditCondition2.SetWindowText(L"�½���");
	}
	if(num==3)
	{
		int nPos=m_PrEle3.GetPos();
		int nLow,nUp;
		m_PrEle3.GetRange(nLow,nUp);
		nPos--;
		if(nPos<=nLow)
		{
			nPos=nLow+1;
		}
		m_PrEle3.SetPos(nPos);
		m_EditCondition3.SetWindowText(L"�½���");
	}
}


void CDialogmain::Stop(int num)//����ֹͣ����
{
	if(num==1)
		m_EditCondition1.SetWindowText(L"ֹͣ");
	if(num==2)
		m_EditCondition2.SetWindowText(L"ֹͣ");
	if(num==3)
		m_EditCondition3.SetWindowText(L"ֹͣ");
}




void CDialogmain::Loading(int num)//���¿͵ĺ�����ʹ��ǰ�������Ա�ֲ�
{
	if(num==1)
		{
			m_EditCondition1.SetWindowText(L"���¿���");
			SetPeople();
		}
	if(num==2)
		{
			m_EditCondition2.SetWindowText(L"���¿���");
			SetPeople();
		}
	if(num==3)
		{
			m_EditCondition3.SetWindowText(L"���¿���");
			SetPeople();
		}
}


void CDialogmain::SetPeople(void)//��ʾ�˷ֲ��ĺ���
{
	m_Flrnum1=p[0];
	m_Flrnum2=p[1];
	m_Flrnum3=p[2];
	m_Flrnum4=p[3];
	m_Flrnum5=p[4];
	m_Flrnum6=p[5];
	m_Flrnum7=p[6];
	m_Flrnum8=p[7];
	m_Flrnum9=p[8];
	m_Flrnum10=p[9];
	m_Flrnum11=p[10];
	m_Flrnum12=p[11];
	m_Flrnum13=p[12];
	m_Flrnum14=p[13];
	m_Flrnum15=p[14];
	m_Flrnum16=p[15];
	m_Flrnum17=p[16];
	m_Flrnum18=p[17];
	m_Flrnum19=p[18];
	m_Flrnum20=p[19];
	UpdateData(FALSE);
}


void CDialogmain::Connection(int* ptemp)//����Ա�ֲ���������ǰ�ˣ��ʼ����
{
	p=ptemp;
}


//void CDialogmain::OnEnChangeEdit2()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
//}


//void CDialogmain::SetTime(int num)
//{
//	
//}


void CDialogmain::SetTime(int num, int time)//��ʾʱ�亯��
{
	if(num==1)
		m_time1=time;
	if(num==2)
		m_time2=time;
	if(num==3)
		m_time3=time;
	UpdateData(FALSE);
}


int CDialogmain::GetRefreshNum(void)//�õ�ˢ�������ĺ�����������Ψһ�������ͱ���
									//���ڿ�ʼ����
{
	UpdateData(TRUE);
	return m_Refreshnum;
}



int CDialogmain::SetTransNum(int transportnum)//������������
{
	m_Transnum=transportnum;
	UpdateData(FALSE);
	return 0;
}