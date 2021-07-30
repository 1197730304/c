
// ConvinceStoreDlg.h: 头文件
//

#pragma once


// CConvinceStoreDlg 对话框
class CConvinceStoreDlg : public CDialogEx
{
// 构造
public:
	CConvinceStoreDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONVINCESTORE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedCancel();
	CButton m_GoodsPay;
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl list_view;
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonGoodsWrite();
	afx_msg void OnBnClickedButtonSystemSet();
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	//afx_msg void OnNMKillfocusList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnEndlabeleditList2(NMHDR* pNMHDR, LRESULT* pResult);
	// 表示客户购买商品总件数
	CEdit m_num;
	// 表示用户购买商品总价
	CEdit m_totalPrices;
};
