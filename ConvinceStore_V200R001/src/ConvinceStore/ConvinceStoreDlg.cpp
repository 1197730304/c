
// ConvinceStoreDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "ConvinceStore.h"
#include "ConvinceStoreDlg.h"
#include "afxdialogex.h"
#include "CGoodsWriteDlg.h"
#include "database.hpp"
#include "CSystemSetDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CConvinceStoreDlg 对话框



CConvinceStoreDlg::CConvinceStoreDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONVINCESTORE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConvinceStoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDCANCEL, m_GoodsPay);
	DDX_Control(pDX, IDC_LIST2, list_view);
	DDX_Control(pDX, IDC_EDIT_NUM, m_num);
	DDX_Control(pDX, IDC_EDIT_PRICE, m_totalPrices);
}

BEGIN_MESSAGE_MAP(CConvinceStoreDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CConvinceStoreDlg::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CConvinceStoreDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CConvinceStoreDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_GOODS_WRITE, &CConvinceStoreDlg::OnBnClickedButtonGoodsWrite)
	ON_BN_CLICKED(IDC_BUTTON_SYSTEM_SET, &CConvinceStoreDlg::OnBnClickedButtonSystemSet)
	ON_BN_CLICKED(IDOK, &CConvinceStoreDlg::OnBnClickedOk)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CConvinceStoreDlg::OnNMDblclkList2)
	//ON_NOTIFY(NM_KILLFOCUS, IDC_LIST2, &CConvinceStoreDlg::OnNMKillfocusList2)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST2, &CConvinceStoreDlg::OnLvnEndlabeleditList2)
	END_MESSAGE_MAP()


// CConvinceStoreDlg 消息处理程序

BOOL CConvinceStoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	DataBaseSrv* db_ = new DataBaseSrv("db_cs.db");
	sqlite3 *dbOpr=nullptr;
	bool ret = db_->ConnectDb(dbOpr);
	if (!ret)
	{
		return false;
	}
	// TODO: 在此添加额外的初始化代码
	m_totalPrices.SetWindowTextW(TEXT("0.0"));
	m_num.SetWindowTextW(TEXT("0"));
	
	DWORD dwStyle = list_view.GetExtendedStyle(); // stcontrol部分
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	list_view.SetExtendedStyle(dwStyle);

	list_view.InsertColumn(1, TEXT("条形码"), LVCFMT_LEFT, 167);
	list_view.InsertColumn(2, TEXT("名称"), LVCFMT_LEFT, 167);
	list_view.InsertColumn(3, TEXT("种类"), LVCFMT_LEFT, 167);
	list_view.InsertColumn(6, TEXT("生产日期"), LVCFMT_LEFT, 167);
	list_view.InsertColumn(5, TEXT("售价"), LVCFMT_LEFT, 167);
	list_view.InsertColumn(6, TEXT("数量"), LVCFMT_LEFT, 167);

	

	list_view.InsertItem(0, TEXT(""));


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CConvinceStoreDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CConvinceStoreDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CConvinceStoreDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}



void CConvinceStoreDlg::OnBnClickedButtonGoodsWrite()
{
	// TODO: 在此添加控件通知处理程序代码
	CGoodsWriteDlg m_GoodsWrite;
	m_GoodsWrite.DoModal();
}



void CConvinceStoreDlg::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}


void CConvinceStoreDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	if (list_view.GetSelectedCount() <= 0) {
		return;
	}
	POSITION pos = list_view.GetFirstSelectedItemPosition();
	while (pos)
	{

		int nSelected = list_view.GetNextSelectedItem(pos); //获取选中行的索引
		
		//更新总价
		CString price = list_view.GetItemText(nSelected, 4);
		CString prices;
		m_totalPrices.GetWindowTextW(prices);
		double Totalprice = _ttof(prices) - _ttof(price);
		prices.Format(_T("%.2f"), Totalprice);
		m_totalPrices.SetWindowTextW(prices);

		list_view.DeleteItem(nSelected); //根据索引删除
		pos = list_view.GetFirstSelectedItemPosition();
	}
	//件数更新
	int num = list_view.GetItemCount();
	CString num_s;
	num_s.Format(_T("%d"), num - 1);
	m_num.SetWindowTextW(num_s);
}

void CConvinceStoreDlg::OnBnClickedButtonSystemSet()
{
	// TODO: 在此添加控件通知处理程序代码
	CSystemSetDlg m_SystemSet;
	m_SystemSet.DoModal();
}


void CConvinceStoreDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	list_view.DeleteAllItems();
	list_view.InsertItem(0, TEXT(""));
	m_num.SetWindowTextW(_T("0"));
	m_totalPrices.SetWindowTextW(_T("0.0"));
	//CDialogEx::OnOK();
}


void CConvinceStoreDlg::OnNMDblclkList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos = list_view.GetFirstSelectedItemPosition();

	int nIndex = list_view.GetNextSelectedItem(pos);

	if (nIndex >= 0)

	{
		list_view.SetFocus();

		CEdit* pEdit = list_view.EditLabel(nIndex);
	}
	*pResult = 0;
}


void CConvinceStoreDlg::OnLvnEndlabeleditList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVDISPINFO* pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strBar = pDispInfo->item.pszText;

	int nIndex = pDispInfo->item.iItem;

	list_view.SetFocus();

	if ((!strBar.IsEmpty()) && nIndex >= 0)

	{
		DataBaseSrv* db_ = new DataBaseSrv("db_cs.db");
		sqlite3* dbOpr = nullptr;
		bool ret = db_->ConnectDb(dbOpr);
		if (!ret)
		{
			MessageBox(_T("连接失败"));
			return;
		}
		string data[10] = { "" };
		string sql = "select bar,name,category,producted_time,outprice from tb_goodsinfo where bar=" + CStringA(strBar) + ";";
		db_->SelectTable(sql, data, 10);

		if (data[1] == "")
		{
			return;
		}
		list_view.InsertItem(nIndex, strBar);
		list_view.SetItemText(nIndex, 1, (CString)data[1].c_str());
		list_view.SetItemText(nIndex, 2, (CString)data[2].c_str());
		list_view.SetItemText(nIndex, 3, (CString)data[3].c_str());
		list_view.SetItemText(nIndex, 4, (CString)data[4].c_str());
		list_view.SetItemText(nIndex, 5, TEXT("1"));

		//获取行数,更新总件数
		int num = list_view.GetItemCount();
		CString num_s;
		num_s.Format(_T("%d"), num-1);
		m_num.SetWindowTextW(num_s);


		//获取单价，更新总价格
		CString prices;
		m_totalPrices.GetWindowTextW(prices);
		double Totalprice = _ttof(prices)+_ttof((CString)data[4].c_str());
		prices.Format(_T("%.2f"), Totalprice);
		m_totalPrices.SetWindowTextW(prices);
	}
	*pResult = 0;
}
