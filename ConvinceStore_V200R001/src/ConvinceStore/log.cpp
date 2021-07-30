#pragma once
#include "log.h"


//日志[时间  日志等级 文件：行号] 具体的日志信息

    void LogTime::GetTimeStamp(std::string* timp_stamp)
    {
        time_t sys_time=time(NULL);
        time(&sys_time);
        struct tm* st = localtime(&sys_time);
        char buf[30] = { 0 };
        snprintf(buf, sizeof(buf) - 1, "%04d-%02d-%02d %02d-%02d-%02d", st->tm_year + 1900,
            st->tm_mon + 1, st->tm_mday, st->tm_hour, st->tm_min, st->tm_sec);
        timp_stamp->assign(buf, strlen(buf));
    }
    void LogTime::CStrReplace( string& src, char old,char news)
    {
        
        assert(src.c_str() != NULL);
        for (int i = 0; i < src.size(); i++)
        {
            if (src[i] == old)
            {
                src[i] = news;
                
            }
            else
            {
                continue;
            }
        }
        
    }

    void LogTime::Log(LogLevel lev, const char* filename,const char* nowfile, int line, const std::string& log_msg)
    {
        //获取日志等级
        std::string log_level = Levels[lev];
        //获取时间戳
        std::string time_stamp;
        LogTime::GetTimeStamp(&time_stamp);

        //组织日志内容
        string logtxt = "[" + time_stamp + " " + log_level + " " + nowfile;
        logtxt += ":";
        logtxt += line;
        logtxt += " ]";
        logtxt += log_msg;
        logtxt += "\n";
        //写入日志内容
        FILE* fp;
        fp = fopen(filename, "at");
        fprintf(fp, logtxt.c_str());
        fclose(fp);

    }





