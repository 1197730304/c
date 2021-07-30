
#include <malloc.h>
#include <string>
#include <vector>
#include "sqlite3.h"
#include <Windows.h>
#include "dbAdp.h"
//#include "../database.hpp"


#ifdef _WIN64
#pragma comment (lib, ".\\db\\lib\\sqlite.lib")
#else
#pragma comment (lib, ".\\db\\lib\\sqlite_x86.lib")
#endif

#pragma warning(disable:6001)

char g_dbDataType[DB_DATA_TYPE_CNT][DB_DATA_TYPE_LEN] =
{
    "INT\0",
    "CHAR(50)\0",
    "CHAR(256)\0",
    "REAL\0"
};

//Unicode 转 Utf8
std::string Unicode2Utf8(const std::wstring& widestring) {
    using namespace std;
    int utf8size = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, NULL, 0, NULL, NULL);
    if (utf8size == 0)
    {
        throw std::exception("Error in conversion.");
    }
    std::vector<char> resultstring(utf8size);
    int convresult = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, &resultstring[0], utf8size, NULL, NULL);
    if (convresult != utf8size)
    {
        throw std::exception("La falla!");
    }
    return std::string(&resultstring[0]);
}
//UTF-8转Unicode 
std::wstring Utf82Unicode(const std::string& utf8string) {
    int widesize = ::MultiByteToWideChar(CP_UTF8, 0, utf8string.c_str(), -1, NULL, 0);
    if (widesize == ERROR_NO_UNICODE_TRANSLATION)
    {
        throw std::exception("Invalid UTF-8 sequence.");
    }
    if (widesize == 0)
    {
        throw std::exception("Error in conversion.");
    }
    std::vector<wchar_t> resultstring(widesize);
    int convresult = ::MultiByteToWideChar(CP_UTF8, 0, utf8string.c_str(), -1, &resultstring[0], widesize);
    if (convresult != widesize)
    {
        throw std::exception("La falla!");
    }
    return std::wstring(&resultstring[0]);
}


int createTbl(char* dbName, char* tblName, KEY_VALUE data[], int iDataCnt)
{
    if ((NULL == dbName) || (NULL == tblName) || (0 >= iDataCnt)) 
    {
        return RET_INVALID_INPUT;
    }

    sqlite3* dbOpr = NULL;;
    int iRet = sqlite3_open(dbName, &dbOpr);
    if (iRet != SQLITE_OK)
    {
        return RET_FAILED_CONNECT_DB;
    }

    char* pSQL = (char*)malloc(1024);
    RET_IF_NULL(pSQL, RET_NULL_PTR);
    memset(pSQL, 0, 1024);
    
    char* pcOper = const_cast<char*>("create table \0");
    size_t iLen = strlen(pcOper);
    strcpy_s(pSQL, strlen(pcOper) + 1, pcOper);
    strcpy_s(pSQL + strlen(pSQL), strlen(tblName) + 1, tblName);
    bool bKeySet = false;
    pSQL[strlen(pSQL)] = '(';
    for (int iLoop = 0; iLoop < iDataCnt; ++iLoop)
    {
        strcpy_s(pSQL + strlen(pSQL), strlen(data[iLoop].m_key.c_str()) + 1, data[iLoop].m_key.c_str());
        pSQL[strlen(pSQL)] = ' ';
        // 暂不支持多种数据类型
        //strcpy_s(pSQL + strlen(pSQL), strlen(g_dbDataType[data[iLoop].m_dataType]) + 1, g_dbDataType[data[iLoop].m_dataType]);
        strcpy_s(pSQL + strlen(pSQL), strlen(g_dbDataType[EM_DB_DATA_TYPE_CHAR_50]) + 1, g_dbDataType[EM_DB_DATA_TYPE_CHAR_50]);
        pSQL[strlen(pSQL)] = ' ';
        if (!bKeySet)
        {
            strcpy_s(pSQL + strlen(pSQL), strlen(DB_KEY_PRIMARY) + 1, DB_KEY_PRIMARY);
            pSQL[strlen(pSQL)] = ' ';
            strcpy_s(pSQL + strlen(pSQL), strlen(DB_VAL_NOT_NULL) + 1, DB_VAL_NOT_NULL);
            bKeySet = true;
        }
        pSQL[strlen(pSQL)] = ',';
    }
    pSQL[strlen(pSQL) - 1] = ')';
    pSQL[strlen(pSQL)] = ';';

    char* pErrMsg = NULL;
    iRet = sqlite3_exec(dbOpr, pSQL, 0, 0, &pErrMsg);
    if (iRet != SQLITE_OK)
    {
        sqlite3_free(pErrMsg);
        iRet = RET_FAILED_SQL_EXEC;
    }
    free(pSQL);
    (void)sqlite3_close(dbOpr);
    return iRet;
}

//数据库语句执行函数
bool Sqlite_Exec(const std::string& sql,const std::string &dbName)
{
    
    sqlite3* dbOpr = NULL;;
    int iRet = sqlite3_open(dbName.c_str(), &dbOpr);
    if (iRet)
    {
        std::cout << "sqlite open failed" << std::endl;
        return false;
    }
    char* pErrMsg = NULL;
    iRet = sqlite3_exec(dbOpr, sql.c_str(), 0, 0, &pErrMsg);
    if (iRet)
    {
        std::cout << "sqlite query failed:" <<pErrMsg <<std::endl;
        return false;
    }
    return true;
}

#define INSERT_USERINFO "insert into tb_userinfo(p_name,p_password,p_sex,p_age,p_in_time,p_status) values(\"%s\",\"%s\",\"%s\",\"%d\",\"%s\",%d)"

bool insertuser(string name,string password,string sex,string time,int age)
{
    
    char buf[1024] = { 0 };
    snprintf(buf, sizeof(buf) - 1, INSERT_USERINFO, name,password, sex, age,time, 1);
    std::cout << buf << std::endl;
    string db_name = "db_cs.db";
    string strbuf = buf;
    wstring res(strbuf.begin(), strbuf.end());
    string tmp = Unicode2Utf8(res);
    bool ret = Sqlite_Exec(tmp, db_name);
    if (!ret)
    {
        std::cout << "insert user failed" << std::endl;
        return false;
    }
    return true;
}


int insertTbl(char* dbName, char* tblName, KEY_VALUE data[], int iDataCnt)
{
    if ((NULL == dbName) || (NULL == tblName) || (0 >= iDataCnt))
    {
        return RET_INVALID_INPUT;
    }

    sqlite3* dbOpr = NULL;;
    int iRet = sqlite3_open(dbName, &dbOpr);
    if (iRet != SQLITE_OK)
    {
        return RET_FAILED_CONNECT_DB;
    }

    char* pSQL = (char*)malloc(2048);
    RET_IF_NULL(pSQL, RET_NULL_PTR);
    memset(pSQL, 0, 2048);
    
    char* pcOper = const_cast<char*>("insert into \0");
    strcpy_s(pSQL, strlen(pcOper) + 1, pcOper);
    strcpy_s(pSQL + strlen(pSQL), strlen(tblName) + 1, tblName);
    pSQL[strlen(pSQL)] = ' ';

    char* pKey = (char*)malloc(512);
    RET_IF_NULL(pKey, RET_NULL_PTR);
    memset(pKey, 0, 512);
    pKey[0] = '(';
    char* pVal = (char*)malloc(512);
    RET_IF_NULL(pVal, RET_NULL_PTR);
    memset(pVal, 0, 512);
    pVal[0] = '(';
    for (int iLoop = 0; iLoop < iDataCnt; ++iLoop)
    {
        strcpy_s(pKey + strlen(pKey), strlen(data[iLoop].m_key.c_str()) + 1, data[iLoop].m_key.c_str());
        pVal[strlen(pVal)] = '\'';
        strcpy_s(pVal + strlen(pVal), strlen(data[iLoop].m_cValue.c_str()) + 1, data[iLoop].m_cValue.c_str());
        pVal[strlen(pVal)] = '\'';
        
        pKey[strlen(pKey)] = ',';
        pVal[strlen(pVal)] = ',';
    }
    pKey[strlen(pKey) - 1] = ')';
    pVal[strlen(pVal) - 1] = ')';
    strcpy_s(pSQL + strlen(pSQL), strlen(pKey) + 1, pKey);
    strcpy_s(pSQL + strlen(pSQL), strlen(" values ") + 1, " values ");
    strcpy_s(pSQL + strlen(pSQL), strlen(pVal) + 1, pVal);
    pSQL[strlen(pSQL)] = ';';

    free(pKey);
    free(pVal);

    char* pErrMsg = NULL;
    iRet = sqlite3_exec(dbOpr, pSQL, 0, 0, &pErrMsg);
    if (iRet != SQLITE_OK)
    {
        sqlite3_free(pErrMsg);
        iRet = RET_FAILED_SQL_EXEC;
    }
    free(pSQL);
    (void)sqlite3_close(dbOpr);

    return iRet;
}

int deleteTbl(char* dbName, char* tblName, KEY_VALUE cond[], int iCondCnt)
{
    if ((NULL == dbName) || (NULL == tblName))
    {
        return RET_INVALID_INPUT;
    }

    sqlite3* dbOpr = NULL;;
    int iRet = sqlite3_open(dbName, &dbOpr);
    if (iRet != SQLITE_OK)
    {
        return RET_FAILED_CONNECT_DB;
    }

    char* pSQL = (char*)malloc(1024);
    RET_IF_NULL(pSQL, RET_NULL_PTR);
    memset(pSQL, 0, 1024);

    strcpy_s(pSQL, strlen("delete from ") + 1, "delete from ");
    strcpy_s(pSQL + strlen(pSQL), strlen(tblName) + 1, tblName);
    pSQL[strlen(pSQL)] = ' ';
    if (0 < iCondCnt)
    {
       strcpy_s(pSQL + strlen(pSQL), strlen(" where ") + 1, " where ");
        for (int iLoop = 0; iLoop < iCondCnt; ++iLoop)
        {
            strcpy_s(pSQL + strlen(pSQL), strlen(cond[iLoop].m_key.c_str()) + 1, cond[iLoop].m_key.c_str());
            strcpy_s(pSQL + strlen(pSQL), strlen(" = \"") + 1, " = \"");
            strcpy_s(pSQL + strlen(pSQL), strlen(cond[iLoop].m_cValue.c_str()) + 1, cond[iLoop].m_cValue.c_str());
            pSQL[strlen(pSQL)] = '\"';
            if (iLoop < iCondCnt - 1)
            {
                strcpy_s(pSQL + strlen(pSQL), strlen(" and ") + 1, " and ");
            }
        }
    }
    pSQL[strlen(pSQL)] = ';';

    char* pErrMsg = NULL;
    iRet = sqlite3_exec(dbOpr, pSQL, 0, 0, &pErrMsg);
    if (iRet != SQLITE_OK)
    {
        sqlite3_free(pErrMsg);
        iRet = RET_FAILED_SQL_EXEC;
    }
    free(pSQL);
    (void)sqlite3_close(dbOpr);

    return iRet;
}

int selectTbl(char* dbName, char* tblName, KEY_VALUE cond[], int iCondCnt, char* data[], int *iDataCnt)
{
    if ((NULL == dbName) || (NULL == tblName) || (0 >= iDataCnt))
    {
        return RET_INVALID_INPUT;
    }

    sqlite3* dbOpr = NULL;;
    int iRet = sqlite3_open(dbName, &dbOpr);
    if (iRet != SQLITE_OK)
    {
        return RET_FAILED_CONNECT_DB;
    }

    char* pSQL = (char*)malloc(1024);
    RET_IF_NULL(pSQL, RET_NULL_PTR);
    memset(pSQL, 0, 1024);

    strcpy_s(pSQL, strlen("select * from ") + 1, "select * from ");
    strcpy_s(pSQL + strlen(pSQL), strlen(tblName) + 1, tblName);
    pSQL[strlen(pSQL)] = ' ';
    if (0 < iCondCnt)
    {
        strcpy_s(pSQL + strlen(pSQL), strlen(" where ") + 1, " where ");
        for (int iLoop = 0; iLoop < iCondCnt; ++iLoop)
        {
            strcpy_s(pSQL + strlen(pSQL), strlen(cond[iLoop].m_key.c_str()) + 1, cond[iLoop].m_key.c_str());
            strcpy_s(pSQL + strlen(pSQL), strlen(" = \"") + 1, " = \"");
            strcpy_s(pSQL + strlen(pSQL), strlen(cond[iLoop].m_cValue.c_str()) + 1, cond[iLoop].m_cValue.c_str());
            pSQL[strlen(pSQL)] = '\"';
            if (iLoop < iCondCnt - 1)
            {
                strcpy_s(pSQL + strlen(pSQL), strlen(" and ") + 1, " and ");
            }
        }
    }
    pSQL[strlen(pSQL)] = ';';

    char* pErrMsg = NULL;
    char** pData;
    int iRowCnt = 0, iColCnt = 0;
    iRet = sqlite3_get_table(dbOpr, pSQL, &pData, &iRowCnt, &iColCnt, &pErrMsg);
    if (iRet != SQLITE_OK)
    {
        sqlite3_free(pErrMsg);
        iRet = RET_FAILED_SQL_EXEC;
    }
    else
    {
        char* pField = NULL;
        char* pValue = NULL;
        int iColIndx = iColCnt;
        int iMaxRowCnt = (iRowCnt < *iDataCnt) ? iRowCnt : *iDataCnt;
        for (int iRow = 0; iRow < iMaxRowCnt; ++iRow)
        {
            char* pRowData = (char*)malloc(1024);
            RET_IF_NULL(pRowData, RET_NULL_PTR);
            memset(pRowData, 0, 1024);
            for (int iCol = 0; iCol < iColCnt; ++iCol)
            {
                pField = pData[iCol];
                pValue = pData[iColIndx];
                iColIndx++;
                
                strcpy_s(pRowData + strlen(pRowData), strlen(pField) + 1, pField);
                pRowData[strlen(pRowData)] = '=';
                strcpy_s(pRowData + strlen(pRowData), strlen(pValue) + 1, pValue);
                if (iCol != iColCnt - 1)
                {
                    pRowData[strlen(pRowData)] = ',';
                }
            }
            data[iRow] = pRowData;
        }

        *iDataCnt = iMaxRowCnt;
    }

    sqlite3_free_table(pData);
    free(pSQL);
    (void)sqlite3_close(dbOpr);

    return iRet;
}

int modifyTbl(char* dbName, char* tblName, KEY_VALUE cond[], int iCondCnt, KEY_VALUE data[], int iDataCnt)
{
    if ((NULL == dbName) || (NULL == tblName) || (0 >= iDataCnt))
    {
        return RET_INVALID_INPUT;
    }

    sqlite3* dbOpr = NULL;;
    int iRet = sqlite3_open(dbName, &dbOpr);
    if (iRet != SQLITE_OK)
    {
        return RET_FAILED_CONNECT_DB;
    }

    char* pSQL = (char*)malloc(1024);
    RET_IF_NULL(pSQL, RET_NULL_PTR);
    memset(pSQL, 0, 1024);

    strcpy_s(pSQL, strlen("update ") + 1, "update ");
    strcpy_s(pSQL + strlen(pSQL), strlen(tblName) + 1, tblName);
    strcpy_s(pSQL + strlen(pSQL), strlen(" set ") + 1, " set ");

    for (int iLoop = 0; iLoop < iDataCnt; ++iLoop)
    {
        strcpy_s(pSQL + strlen(pSQL), strlen(data[iLoop].m_key.c_str()) + 1, data[iLoop].m_key.c_str());
        strcpy_s(pSQL + strlen(pSQL), strlen(" = \"") + 1, " = \"");
        strcpy_s(pSQL + strlen(pSQL), strlen(data[iLoop].m_cValue.c_str()) + 1, data[iLoop].m_cValue.c_str());
        pSQL[strlen(pSQL)] = '\"';
        if (iLoop < iDataCnt - 1)
        {
            strcpy_s(pSQL + strlen(pSQL), strlen(", "), ", ");
        }
    }

    if (0 < iCondCnt)
    {
        strcpy_s(pSQL + strlen(pSQL), strlen(" where ") + 1, " where ");
        for (int iLoop = 0; iLoop < iCondCnt; ++iLoop)
        {
            strcpy_s(pSQL + strlen(pSQL), strlen(cond[iLoop].m_key.c_str()) + 1, cond[iLoop].m_key.c_str());
            strcpy_s(pSQL + strlen(pSQL), strlen(" = \"") + 1, " = \"");
            strcpy_s(pSQL + strlen(pSQL), strlen(cond[iLoop].m_cValue.c_str()) + 1, cond[iLoop].m_cValue.c_str());
            pSQL[strlen(pSQL)] = '\"';
            if (iLoop < iCondCnt - 1)
            {
                strcpy_s(pSQL + strlen(pSQL), strlen(" and ") + 1, " and ");
            }
        }
    }
    pSQL[strlen(pSQL)] = ';';

    char* pErrMsg = NULL;
    iRet = sqlite3_exec(dbOpr, pSQL, 0, 0, &pErrMsg);
    if (iRet != SQLITE_OK)
    {
        sqlite3_free(pErrMsg);
        iRet = RET_FAILED_SQL_EXEC;
    }
    free(pSQL);
    (void)sqlite3_close(dbOpr);

    return iRet;
}

int selectTblFreeMem(char* data[], int iDataCnt)
{
    for (int iLoop = 0; iLoop < iDataCnt; ++iLoop)
    {
        if (NULL != data[iLoop])
        {
            free(data[iLoop]);
        }
    }
    return RET_SUCCESS;
}
