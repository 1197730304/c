#ifndef	 _XXXX_
#define  _XXXX_
#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include"db/sqlite3.h"
#include "log.h"
using namespace std;
#define INSERT_USER "insert into tb_userinfo(p_name,p_password,p_sex,p_age,p_in_time,p_status) values(\"%s\",\"%s\",\"%s\",\"%d\",\"%s\",\"%d\")"
#define INSERT_PRODUCT "insert into \"%s\"(bar,name,category,inprice,outprice,amount,producted_time) values(\"%s\",\"%s\",\"%s\",\"%lf\",\"%lf\",\"%d\",\"%s\")"
#define INSERT_TYPE "insert into tb_goodstype(type) values(\"%s\")"
#define DELETE_TYPE "delete from tb_goodstype where type=\"%s\""
#define SELET_GOODSINFO "select bar,name from tb_goodsinfo where bar=\"%s\""
class CTools
{
public:
	static string WCharToMByte(LPCWSTR lpcwszStr)
	{
		string str;
		DWORD dwMinSize = 0;
		LPSTR lpszStr = NULL;
		dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, NULL, 0, NULL, FALSE);
		if (0 == dwMinSize)
		{
			return FALSE;
		}
		lpszStr = new char[dwMinSize];
		WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, lpszStr, dwMinSize, NULL, FALSE);
		str = lpszStr;
		delete[] lpszStr;
		return str;
	}

	static CString FormatDateTimeISO8601(const COleDateTime& dt)
	{
		ASSERT(dt.m_status == COleDateTime::valid);

		CString strValue;

		if ((DWORD)dt == 0)
		{
			strValue = dt.Format(_T("%H:%M:%S"));
		}
		else
		{
			strValue = dt.Format(_T("%Y-%m-%d"));
		}
		return strValue;
	}

	static char* U2G(const char* utf8)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
		wchar_t* wstr = new wchar_t[len + 1];
		memset(wstr, 0, len + 1);
		MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
		len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
		char* str = new char[len + 1];
		memset(str, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
		if (wstr) delete[] wstr;
		return str;
	}
	static char* G2U(const char* gb2312)
	{
		int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
		wchar_t* wstr = new wchar_t[len + 1];
		memset(wstr, 0, len + 1);
		MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
		len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
		char* str = new char[len + 1];
		memset(str, 0, len + 1);
		WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
		if (wstr) delete[] wstr;
		return str;
	}
};


class DataBaseSrv
{
public:
	DataBaseSrv(const std::string& db_name)
	{
		db_ = db_name;
		dbOpr_ = nullptr;
		errmsg_ = nullptr;
	}

	~DataBaseSrv()
	{
		sqlite3_close(dbOpr_);
	}

	bool ConnectDb(sqlite3* dbOpr)
	{
		int rc = sqlite3_open(db_.c_str(), &dbOpr_);

		if (rc) {
			
			return false;
		}
		else {
			
			return true;
		}

	}

	bool QuerySql(const std::string& sql)
	{

		int ret = sqlite3_exec(dbOpr_, CTools::G2U(sql.c_str()), 0, 0, &errmsg_);
		if (ret)
		{
			return false;
		}
		return true;
	}

	bool DeleteType(const string& type)
	{
		char buf[1024] = { 0 };
		snprintf(buf, sizeof(buf) - 1, DELETE_TYPE, type.c_str());
		bool ret = QuerySql(buf);
		if (!ret)
		{
			return false;
		}
		return true;
	}
 
	 bool InsertType(const string& type)
	{
		char buf[1024] = { 0 };
		snprintf(buf, sizeof(buf) - 1, INSERT_TYPE,type.c_str());
		bool ret = QuerySql(buf);
		if (!ret)
		{
			return false;
		}
		return true;
	 }

	 bool InsertProduct(const string& tbName,const string& bar,const string& name,const string& category, double inprice,double outprice,int amount,const string& time)
	{
		char buf[1024] = { 0 };
		snprintf(buf, sizeof(buf) - 1, INSERT_PRODUCT,tbName.c_str(),bar.c_str(),name.c_str(), category.c_str(), inprice,outprice,amount, time.c_str());
		bool ret = QuerySql(buf);
		if (!ret)
		{
			return false;
		}
		return true;

	 }

	 bool SelectTable(const string& sql, string data[],int len)
	 {
		 bool ret=ConnectDb(dbOpr_);
		 if (!ret)
		 {
			 return false;
		 }
		 char** dbResult;

		 char* errmsg = nullptr;
		 int nRow = 0, nColumn = 0;     //nRow 查找出的总行数,nColumn 存储列  
		 ret = sqlite3_get_table(dbOpr_, CTools::G2U(sql.c_str()), &dbResult, &nRow, &nColumn, &errmsg);
		 if (ret)
		 {
			 sqlite3_free(errmsg);
			 return false;
		 }
		 int count = nColumn;
		 int index = 0;
		 for (int i = 0; i < nRow; i++) {
			 
			 for (int j = 0; j < nColumn; j++) {
				 char* pRowData = (char*)malloc(1024);
				 memset(pRowData, 0, 1024);
				 pRowData = dbResult[count];
				 count++;
				 if (index < len)
				 {
					data[index++] = CTools::U2G(pRowData);
				 }
				 else
				 {
					 return false;
				 }
				 //free(pRowData);
				
			 }

			 
		 }
		 return true;
	 }


private:
	std::string db_;
	sqlite3* dbOpr_;
	char* errmsg_;


};
#endif