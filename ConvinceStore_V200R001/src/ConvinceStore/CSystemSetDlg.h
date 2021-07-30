#pragma once


// CSystemSetDlg 对话框

class CSystemSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSystemSetDlg)

public:
	CSystemSetDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSystemSetDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SYSTEM_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	// 在系统设置界面设置商品类别
	CComboBox m_GoodsType;
	afx_msg void OnBnClickedButtonAddType();
	afx_msg void OnBnClickedButtonDeleteType();
	CMFCEditBrowseCtrl m_LogLoad;
	afx_msg void OnEnChangeMfceditbrowse1();
};
