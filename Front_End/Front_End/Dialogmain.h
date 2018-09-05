#pragma once


/*#include "stdafx.h"
#include "Front_End.h"
//#include "Dialogmain.h"
#include "afxdialogex.h"*/



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
//	void MoveUp(int num);
	virtual BOOL OnInitDialog();
//	void MoveDown(int num);
//	void Stop(int num);
//	void Loading(int num);
	void SetPeople(void);
	void Connection(int* ptemp);
//	afx_msg void OnEnChangeEdit2();
//	CEdit m_time1;
	int m_time1;
	int m_time3;
	int m_time2;
	void SetTime(int num, int time);
//	int GetRefreshNum(void);
	int SetTransNum(int transportnum);
	int PrevCondition[3];
	int PrevFrontCondition[3];
	double m_PreFlr[3];
	double m_PreFrontFlr[3];
//	void ResetCondition(int num);
//	void ResetConditionDown(int num);
//	void ResetConditionUp(int num);
	int v;
	afx_msg void OnBnClickedAcc2();
	afx_msg void OnBnClickedAcc10();
	afx_msg void OnBnClickedAcc20();
	afx_msg void OnBnClickedAcc50();
	afx_msg void OnBnClickedButtonpause();
	afx_msg void OnBnClickedButtoncontinue();
	int m_objflr1;
	int m_objflr2;
	int m_objflr3;
	void SetObjflr(int num, int objflr);
	double m_preflr1;
	double m_preflr2;
	double m_preflr3;
	void SetPreflr(int num, double preflr);
	int m_Acc;
	int m_Inside1;
	int m_Inside2;
	int m_Inside3;
	void SetInside(int num, int inside);
	CEdit m_Ifrepair1;
	CEdit m_Ifrepair2;
	CEdit m_Ifrepair3;
	void SetRepair(int num, int isok);
};
