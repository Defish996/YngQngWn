#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <cstdarg> //可变参数宏依赖

enum // 日志等级
{
    Debug = 0,
    Info,    // 常规信息
    Warning, // 警告信息
    Error,   // 错误信息,但还是可以运行
    Fatal    // 重大错误,代码终止

};
std::string LevelToString(int level)
{
    switch (level)
    {
    case Debug:
        return "Debug";
    case Info:
        return "Info";
    case Warning:
        return "Warning";
    case Error:
        return "Error";
    case Fatal:
        return "Fatal";
    default:
        return "Unknown";
    }
}
// 日志
class Log
{
public:
    Log()
    {
    }
    // 设计成类似c语言形式的接口,方便像printf函数那样打印不同类别的信息,支持可变参数
    // LogMessage(LogLevel, "%s, %d, %f..."....);//日志等级 打印的信息
    void LogMessage(int level, const char *format, ...)
    {
        // struct tm *tm = localtime((const time_t *)time(nullptr));
        const time_t t = time(nullptr);//获取时间戳
        std::string tm = GetTime(t);//将时间戳转化为年月日时分秒的string
        char content[1024];
        va_list args; // const char *, va_等的用来对付可变参数的函数
        va_start(args, format);//初始化()
        // args指向了可变参数部分
        vsnprintf(content, sizeof(content), format, args); // 可变参数家族函数之一, 将可变参数内容输入到content中
        va_end(args);                                      // args == nullptr

        printf("[%s][%s]%s", LevelToString(level).c_str(), tm.c_str(), content);
    }
    ~Log()
    {
    }

private:
    std::string GetTime(const time_t &t)
    {
        struct tm *tm = localtime(&t);//将时间戳转为struct tm *类型,这个结构体内置的变量可以获取对应的时间
        //年的计时从1900开始,所以计算当前要加1900, 月默认从0开始记,所以加1 这一点在man手册中也有说明
        return std::to_string(tm->tm_year + 1900) + "年" + std::to_string(tm->tm_mon + 1) + "月" \
             + std::to_string(tm->tm_mday) + "日" + std::to_string(tm->tm_hour) + ":" \
             + std::to_string(tm->tm_min) + ":" + std::to_string(tm->tm_sec);
    }
};
