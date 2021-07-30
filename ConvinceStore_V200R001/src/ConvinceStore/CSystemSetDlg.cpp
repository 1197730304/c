// CSystemSetDlg.cpp: 实现文件
//

#include "pch.h"
#include "ConvinceStore.h"
#include "CSystemSetDlg.h"
#include "afxdialogex.h"
#include "database.hpp"
#include "log.h"


// CSystemSetDlg 对话框

IMPLEMENT_DYNAMIC(CSystemSetDlg, CDialogEx)

CSystemSetDlg::CSystemSetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SYSTEM_SEETING, pParent)
{

}

CSystemSetDlg::~CSystemSetDlg()
{
}

void CSystemSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SET_TYPE, m_GoodsType);
	DDX_Control(pDX, IDC_MFCEDITBROWSE2, m_LogLoad);
}


BEGIN_MESSAGE_MAP(CSystemSetDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSystemSetDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_ADD_TYPE, &CSystemSetDlg::OnBnClickedButtonAddType)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_TYPE, &CSystemSetDlg::OnBnClickedButtonDeleteType)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CSystemSetDlg::OnEnChangeMfceditbrowse1)
END_MESSAGE_MAP()


// CSystemSetDlg 消息处理程序


void CSystemSetDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//CDialogEx::OnOK();
	CString load;
	GetDlgItemText(IDC_MFCEDITBROWSE2,load);
	string msg = "更改日志存储路径";
	string& tmp = CTools::WCharToMByte(load);
	LogTime::CStrReplace(tmp, '\\', '/');
	tmp += "/123.log";
	
	LOG(INFO, tmp.c_str(), msg);
	SetDlgItemText(IDC_MFCEDITBROWSE2, _T(""));
	

}

BOOL getTypeDataFromDB(string data[], DataBaseSrv* db)
{
	sqlite3* dbOpr = nullptr;
	bool ret = db->ConnectDb(dbOpr);
	if (!ret)
	{
		return false;
	}
	const string& sql = "select * from tb_goodstype;";
	db->SelectTable(sql, data, 25);
	return true;
}

BOOL CSystemSetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DataBaseSrv* db = new DataBaseSrv("db_cs.db");
	string data[25] = { "" };
	getTypeDataFromDB(data, db);
	int num = 0;
	while (data[num] != "")
	{
		m_GoodsType.AddString((CString)data[num].c_str());
		num++;
	}
	
	return true;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CSystemSetDlg::OnBnClickedButtonAddType()
{
	// TODO: 在此添加控件通知处理程序代码
	DataBaseSrv* db = new DataBaseSrv("db_cs.db");
	string data[25] = { "" };
	bool ConnectState = getTypeDataFromDB(data, db);
	if (!ConnectState)
	{
		MessageBox(_T("数据库连接失败"));
	}
	int num = 0;
	int flag = true;
	CString add_type;
	GetDlgItemText(IDC_COMBO_SET_TYPE, add_type);
	while (data[num] != "")
	{
		if (add_type == (CString)data[num].c_str())
		{
			flag = false;
			MessageBox(_T("种类已存在"));
		}
		num++;
	}
	if (flag)
	{
		bool re = db->InsertType(CTools::WCharToMByte(add_type));
		if (!re)
		{
			MessageBox(_T("插入失败"));
		}
		else
		{
			m_GoodsType.AddString(add_type);
		}
		
	}
	return;
}


void CSystemSetDlg::OnBnClickedButtonDeleteType()
{
	// TODO: 在此添加控件通知处理程序代码
	DataBaseSrv* db = new DataBaseSrv("db_cs.db");
	string data[25] = { "" };
	bool ConnectState = getTypeDataFromDB(data, db);
	if (!ConnectState)
	{
		MessageBox(_T("数据库连接失败"));
	}
	int num = 0;
	int flag = false;
	CString del_type;
	GetDlgItemText(IDC_COMBO_SET_TYPE, del_type);
	while (data[num] != "")
	{
		if (del_type == (CString)data[num].c_str())
		{
			flag = TRUE;
		}
		num++;
	}
	if (flag)
	{
		bool re = db->DeleteType(CTools::WCharToMByte(del_type));
		if (!re)
		{
			MessageBox(_T("删除失败"));
		}
		else
		{
			int index = m_GoodsType.GetCurSel();
			m_GoodsType.DeleteString(index);
		}
	}
	return;
}


void CSystemSetDlg::OnEnChangeMfceditbrowse1()
{
	CString selectedPath;

	GetDlgItemText(IDC_MFCEDITBROWSE1, selectedPath);
}
