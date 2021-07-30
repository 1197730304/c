#pragma once
#define DB_DATA_TYPE_CNT 32
#define DB_DATA_TYPE_LEN 32
#define DB_DATA_FIELD_LEN   256
#define DB_DATA_RECORD_LEN  256
#define DB_KEY_PRIMARY "primary key"
#define DB_VAL_NOT_NULL "not null"


#define RET_NULL_PTR            -2
#define RET_INVALID_INPUT       -1
#define RET_SUCCESS             0
#define RET_FAILED_CONNECT_DB   1
#define RET_FAILED_SQL_EXEC     2

#define RET_IF_NULL(ptr, ret) \
if (NULL == ptr)\
{\
    return ret;\
}

#include <cstring>
#include <string>
#include<iostream>
#include"../db.hpp"
using namespace std;
enum DB_DATA_TYPE
{
    EM_DB_DATA_TYPE_INT = 0,
    EM_DB_DATA_TYPE_CHAR_50,
    EM_DB_DATA_TYPE_CHAR_256,
    EM_DB_DATA_TYPE_REAL,
    EM_DB_DATA_TYPE_BOOLEAN,
    EM_DB_DATA_TYPE_BOT = DB_DATA_TYPE_CNT
};

typedef struct
{
    /*char m_key[DB_DATA_FIELD_LEN];
    char m_cValue[DB_DATA_RECORD_LEN];*/
    string m_key;
    string m_cValue;
    DB_DATA_TYPE m_dataType;
}KEY_VALUE;

bool Sqlite_Exec(const std::string& sql, const std::string& dbName);
bool insertuser(string name, string password,string sex, string time, int age);
int createTbl(char* dbName, char* tblName, KEY_VALUE data[], int iDataCnt);
int insertTbl(char* dbName, char* tblName, KEY_VALUE data[], int iDataCnt);
int deleteTbl(char* dbName, char* tblName, KEY_VALUE cond[], int iCondCnt);
int selectTbl(char* dbName, char* tblName, KEY_VALUE cond[], int iCondCnt, char* data[], int *iDataCnt);
int modifyTbl(char* dbName, char* tblName, KEY_VALUE cond[], int iCondCnt, KEY_VALUE data[], int iDataCnt);

// 在调用selectTbl函数并处理完结果后，应该调用该函数释放存储查询结果的内存
int selectTblFreeMem(char* data[], int iDataCnt);