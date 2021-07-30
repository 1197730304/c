// CGoodsWriteDlg.cpp: 实现文件
//

#include "pch.h"
#include "ConvinceStore.h"
#include "CGoodsWriteDlg.h"
#include "afxdialogex.h"
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include"database.hpp"

#include "ConvinceStoreDlg.h"

#define ZERO 0
#define TWOHUNDRED 200
#define ONETHUNSAND 1000


// CGoodsWriteDlg 对话框

IMPLEMENT_DYNAMIC(CGoodsWriteDlg, CDialogEx)

CGoodsWriteDlg::CGoodsWriteDlg(CWnd* pParent )
	: CDialogEx(IDD_DIALOG1, pParent)
	, product_bar(_T(""))
	, product_name(_T(""))
	, m_product_kind()
	, product_num(0)
	, product_inprice(0.0)
	, product_outprice(0.0)
	, product_time(COleDateTime::GetCurrentTime())
{

}

CGoodsWriteDlg::~CGoodsWriteDlg()
{
}

void CGoodsWriteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDCANCEL, m_GoodsWrite);
	DDX_Control(pDX, IDC_EDIT_INITIAL_PRICE, m_inprice);
	DDX_Control(pDX, IDC_EDIT_FINAL_PRICE, m_outprice);
	DDX_Control(pDX, IDC_EDIT_GOODS_NUM, m_num);
	DDX_Text(pDX, IDC_EDIT_BAR_CODE, product_bar);
	DDX_Text(pDX, IDC_EDIT_GOODS_NAME, product_name);
	DDX_Text(pDX, IDC_EDIT_GOODS_NUM, product_num);
	DDX_Text(pDX, IDC_EDIT_INITIAL_PRICE, product_inprice);
	DDX_Text(pDX, IDC_EDIT_FINAL_PRICE, product_outprice);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_GOODS_DATE, product_time);
	DDX_Control(pDX, IDC_EDIT_GOODS_NAME, m_name);
	DDX_Control(pDX, IDC_EDIT_BAR_CODE, m_barcode);
	DDX_CBString(pDX, IDC_COMBO_PRODUCT_KIND, m_product_kind);
	DDX_Control(pDX, IDC_COMBO_PRODUCT_KIND, m_Product_Kind);
}


BEGIN_MESSAGE_MAP(CGoodsWriteDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &CGoodsWriteDlg::OnBnClickedOk)
	ON_EN_KILLFOCUS(IDC_EDIT_GOODS_NAME, &CGoodsWriteDlg::OnEnKillfocusEditGoodsName)
	ON_EN_KILLFOCUS(IDC_EDIT_GOODS_NUM, &CGoodsWriteDlg::OnEnKillfocusEditGoodsNum)
	ON_EN_KILLFOCUS(IDC_EDIT_INITIAL_PRICE, &CGoodsWriteDlg::OnEnKillfocusEditInitialPrice)
	ON_EN_KILLFOCUS(IDC_EDIT_FINAL_PRICE, &CGoodsWriteDlg::OnEnKillfocusEditFinalPrice)
END_MESSAGE_MAP()


// CGoodsWriteDlg 消息处理程序


void CGoodsWriteDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	

	//数量0----200---int
	CString str3;
	GetDlgItemText(IDC_EDIT_GOODS_NUM, str3);
	std::string strCnt = CStringA(str3);
	int m_amount = atoi(strCnt.c_str());


	////进价 0---1000---float
	CString str1;
	GetDlgItemText(IDC_EDIT_INITIAL_PRICE, str1);
	std::string str1Cnt = CStringA(str1);
	double m_intPrice = atof(str1Cnt.c_str());
	

	//售价0---1000---float
	CString str2;
	GetDlgItemText(IDC_EDIT_FINAL_PRICE, str2);
	std::string str2Cnt = CStringA(str2);
	double m_outPrice = atof(str2Cnt.c_str());


	//和数据库建立连接!str4.IsEmpty() && 
	if (m_amount > ZERO && m_amount < TWOHUNDRED && m_intPrice>ZERO && m_intPrice < ONETHUNSAND && m_outPrice>ZERO && m_outPrice < ONETHUNSAND)
	{
		
		string tbName = "tb_goodsinfo";
		DataBaseSrv* db_ = new DataBaseSrv("db_cs.db");
		sqlite3* dbOpr=nullptr;
		bool ret = db_->ConnectDb(dbOpr);
		if (!ret)
		{
			MessageBox(_T("连接失败"));
			return;
		}
		string name = CTools::WCharToMByte(product_name);
		CString timestr = CTools::FormatDateTimeISO8601(product_time);
		string time = CT2A(timestr);
		int acount = product_num;
		string bar = CTools::WCharToMByte(product_bar);
		string type = CTools::WCharToMByte(m_product_kind);
		ret = db_->InsertProduct(tbName,bar, name, type, product_inprice, product_outprice, acount, time);

		if (!ret)
		{
			MessageBox(_T("商品录入失败"));
		}

		m_barcode.SetWindowText(_T(""));
		m_outprice.SetWindowText(_T(""));
		m_inprice.SetWindowText(_T(""));
		m_num.SetWindowText(_T(""));
		m_name.SetWindowText(_T(""));
	}
	else
	{
		MessageBox(_T("商品信息有误，请重新输入！"));
	}
}




void CGoodsWriteDlg::OnEnKillfocusEditGoodsName()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str4;
	GetDlgItemText(IDC_EDIT_GOODS_NAME, str4);
	if (str4.IsEmpty())
	{
		MessageBox(_T("请输入商品名称"));
	}
	else
	{
		UpdateData(TRUE);
	}

}


void CGoodsWriteDlg::OnEnKillfocusEditGoodsNum()
{
	// TODO: 在此添加控件通知处理程序代码
	//数量0----200---int
	CString str3;
	GetDlgItemText(IDC_EDIT_GOODS_NUM, str3);
	std::string strCnt = CStringA(str3);
	int m_amount = atoi(strCnt.c_str());
	if (m_amount > ZERO && m_amount < TWOHUNDRED)
	{
		UpdateData(TRUE);
	}
	else
	{
		m_num.SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT_GOODS_NUM)->SetWindowText(_T("0"));
	}

}


void CGoodsWriteDlg::OnEnKillfocusEditInitialPrice()
{
	// TODO: 在此添加控件通知处理程序代码
	//进价 0---1000---float
	CString str1;
	GetDlgItemText(IDC_EDIT_INITIAL_PRICE, str1);
	std::string str1Cnt = CStringA(str1);
	double m_intPrice = atof(str1Cnt.c_str());
	if (m_intPrice > ZERO && m_intPrice < ONETHUNSAND)
	{
		UpdateData(TRUE);
	}
	else
	{
		m_inprice.SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT_INITIAL_PRICE)->SetWindowText(_T("0.0"));
	}
}


void CGoodsWriteDlg::OnEnKillfocusEditFinalPrice()
{
	// TODO: 在此添加控件通知处理程序代码

	//售价0---1000---float
	CString str2;
	GetDlgItemText(IDC_EDIT_FINAL_PRICE, str2);
	std::string str2Cnt = CStringA(str2);
	double m_outPrice = atof(str2Cnt.c_str());
	if (m_outPrice > ZERO && m_outPrice < ONETHUNSAND)
	{
		UpdateData(TRUE);
	}
	else
	{
		m_outprice.SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT_FINAL_PRICE)->SetWindowText(_T("0.0"));
	}


}


BOOL CGoodsWriteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DataBaseSrv* db = new DataBaseSrv("db_cs.db");
	sqlite3* dbOpr = nullptr;
	bool ret = db->ConnectDb(dbOpr);
	if (!ret)
	{
		return FALSE;
	}
	const string& sql = "select * from tb_goodstype;";
	string data[25] = { "" };
	db->SelectTable(sql, data, 25);
	int num = 0;
	while (data[num] != "")
	{
		m_Product_Kind.AddString((CString)data[num].c_str());
		num++;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
