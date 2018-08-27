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
};
