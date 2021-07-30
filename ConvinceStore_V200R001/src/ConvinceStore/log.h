#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<string>
#include<algorithm>
#include<assert.h>
#define LOG(lev,filename,msg) LogTime::Log(lev,filename,__FILE__ , __LINE__ ,msg)
using namespace std;

//划分日志的等级
static const char* Levels[] = {
    "INFO",
    "WARNING",
    "ERRORS",
    "FATAL",
    "DEBUG"
};

enum LogLevel
{
    INFO = 0,
    WARNING,
    ERRORS,
    FATAL,
    DEBUG
};

class LogTime
{
public:
    static void GetTimeStamp(std::string* timp_stamp);
    static void CStrReplace(string& src, char old, char news);

    static void Log(LogLevel lev, const char* filename, const char* nowfile, int line, const std::string& log_msg);

};






