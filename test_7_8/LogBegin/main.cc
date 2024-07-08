#include "Log.hpp"
int main()
{
    Log lg;
    lg.LogMessage(Debug, "haha %s, %f, %d\n", "hehe", 3.14, 7);
    lg.LogMessage(Info, "haha %s, %f, %d\n", "hehe", 3.14, 7);
    lg.LogMessage(Warning, "haha %s, %f, %d\n", "hehe", 3.14, 7);
    lg.LogMessage(Fatal, "haha %s, %f, %d\n", "hehe", 3.14, 7);
    lg.LogMessage(Debug, "haha %s, %f, %d\n", "hehe", 3.14, 7);



    return 0;
}