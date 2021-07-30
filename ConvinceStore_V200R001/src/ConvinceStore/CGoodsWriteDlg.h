#pragma once

// CGoodsWriteDlg 对话框
class CGoodsWriteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsWriteDlg)

public:
	CGoodsWriteDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGoodsWriteDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_GoodsWrite;
	afx_msg void OnEnChangeEditGoodsPrice();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditBarCode();
	afx_msg void OnBnClickedCancel();

	CString product_bar;
	CString product_name;
	CString m_product_kind;
	int product_num;
	double product_inprice;
	double product_outprice;
	COleDateTime product_time;
	CEdit m_inprice;
	CEdit m_outprice;
	CEdit m_num;
	CEdit m_name;
	CEdit m_barcode;
	
	afx_msg void OnCbnSelchangeComboProductKind();
	virtual BOOL OnInitDialog();
	CComboBox m_Product_Kind;

	afx_msg void OnEnKillfocusEditGoodsName();
	afx_msg void OnEnKillfocusEditGoodsNum();
	afx_msg void OnEnKillfocusEditInitialPrice();
	afx_msg void OnEnKillfocusEditFinalPrice();
};
