#pragma once


/*#include "stdafx.h"
#include "Temp1001.h"
//#include "Dialogmain.h"
#include "afxdialogex.h"*/
//#include "People.h"



// CDialogmain 对话框

class CDialogmain : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogmain)

public:
	CDialogmain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogmain();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EditCondition1;
	CEdit m_EditCondition2;
	CEdit m_EditCondition3;
	int m_Flrnum1;
	int m_Flrnum10;
	int m_Flrnum11;
	int m_Flrnum12;
	int m_Flrnum13;
	int m_Flrnum14;
	int m_Flrnum15;
	int m_Flrnum16;
	int m_Flrnum17;
	int m_Flrnum18;
	int m_Flrnum19;
	int m_Flrnum2;
	int m_Flrnum20;
	int m_Flrnum3;
	int m_Flrnum4;
	int m_Flrnum5;
	int m_Flrnum6;
	int m_Flrnum7;
	int m_Flrnum8;
	int m_Flrnum9;
	afx_msg void OnClickedStart();
	int m_Refreshnum;
	int m_Transnum;
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int Vtime;
	CProgressCtrl m_PrEle1;
	CProgressCtrl m_PrEle2;
	CProgressCtrl m_PrEle3;
	void MoveUp(int num);
	virtual BOOL OnInitDialog();
	void MoveDown(int num);
	void Stop(int num);
	void Loading(int num);
	void SetPeople(void);
	int* p;
	void Connection(int* ptemp);
//	afx_msg void OnEnChangeEdit2();
//	CEdit m_time1;
	int m_time1;
	int m_time3;
	int m_time2;
	void SetTime(int num, int time);
	int GetRefreshNum(void);
	int SetTransNum(int transportnum);
	int PrevCondition1;
	int PrevCondition2;
	int PrevCondition3;
	int PrevFrontCondition1;
	int PrevFrontCondition2;
	int PrevFrontCondition3;
	int PrevCondition[3];
	int PrevFrontCondition[3];
};
