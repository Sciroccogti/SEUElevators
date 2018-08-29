#pragma once


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
	CEdit m_EditCondition1;//状态编辑
	CEdit m_EditCondition2;
	CEdit m_EditCondition3;
	///////////////////////////
//	int m_Flrnum1;
	//各层人数
//	int m_Flrnum10;
//	int m_Flrnum11;
//	int m_Flrnum12;
//	int m_Flrnum13;
//	int m_Flrnum14;
//	int m_Flrnum15;
//	int m_Flrnum16;
//	int m_Flrnum17;
//	int m_Flrnum18;
//	int m_Flrnum19;
//	int m_Flrnum2;
//	int m_Flrnum20;
//	int m_Flrnum3;
//	int m_Flrnum4;
//	int m_Flrnum5;
//	int m_Flrnum6;
//	int m_Flrnum7;
//	int m_Flrnum8;
//	int m_Flrnum9;
	//////////////////////
	afx_msg void OnClickedStart();
	////////////////////////////
	int m_Refreshnum;//刷人人数
	int m_Transnum;//已运人数
	//////////////////////////
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	//////////////////////////////
	int Vtime;//总时间
	CProgressCtrl m_Progress_ele1;//电梯进度条控件
	CProgressCtrl m_Progress_ele2;
	CProgressCtrl m_Progress_ele3;
	////////////////////////////////
	void SetEleMotion(int num, int mode, int vtime);

	int keytime1;
	int keytime2;//实时计时
	int keytime3;

	int countime1;
	int countime2;
	int countime3;
//	void UpdateTime(void);
//	CString m_Time;
//	int m_time1;
	int m_time1;
	int m_time2;
	int m_time3;
	void UpdateTime(int num);
//	void UpdateCondition(int num, int mode);
	void SetPeople(void);
	afx_msg void OnEnChangeEditf20();
	int m_flrnum1;
	int m_flrnum10;
	int m_flrnum11;
	int m_flrnum12;
	int m_flrnum13;
	int m_flrnum14;
	int m_flrnum15;
	int m_flrnum16;
	int m_flrnum17;
	int m_flrnum18;
	int m_flrnum19;
	int m_flrnum2;
	int m_flrnum20;
	int m_flrnum3;
	int m_flrnum4;
	int m_flrnum5;
	int m_flrnum6;
	int m_flrnum7;
	int m_flrnum8;
	int m_flrnum9;
	int* p;
	void Connect(int* ptemp);
};
