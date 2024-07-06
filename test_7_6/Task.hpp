#pragma once
#include <iostream>
#include <string>
#include <unistd.h>
enum //设置退出码
{
    ok = 0,
    div_zero,
    mod_zero,
    unknow
};
const std::string opts = "+-*/%)[()]"; //设置随机运算
class Task
{
public:
    Task()//无参构造函数用于生成无参临时对象,如果有参构造是全缺省那么可以不用写这个无参构造函数
    {}
    Task(int x, int y, char op)
    :data_x(x), data_y(y), opt(op), result(0), code(ok)
    {}
    void Run()//任务主题内容
    {
        switch(opt)
        {
            case '+':
                result = data_x + data_y;
                break;
            case '-':
                result = data_x - data_y;
                break;
            case '*':
                result = data_x * data_y;
                break;
            case '/':
            {
                if(data_y == 0)
                {
                    code = div_zero;
                }
                else
                {
                    result = data_x / data_y;
                }
                break;
            }
            case '%':
            {
                if(data_y == 0)
                {
                    code = mod_zero;
                }
                else
                {
                    result = data_x % data_y;
                }
                break;
            }
            default:
                code = unknow;
                break;
        }
    }
    void operator()()
    {
        Run();
    }
    ~Task()
    {}
    //打印任务,用于更清晰的认识
    std::string print_task()
    {
        std::string s;
        s = std::to_string(data_x) + opt + std::to_string(data_y) + "=?";
        return s;
    }
    std::string print_result()
    {
        std::string s;
        s = std::to_string(data_x) + opt + std::to_string(data_y) + "=" + std::to_string(result) + "[" + std::to_string(code) + "]";
        return s;
    }
private:
    int data_x;
    int data_y;
    char opt;

    int result;
    int code;
};