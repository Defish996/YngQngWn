//leetcode 2710. 移除字符串中的尾随零


class Solution {
public:
    string removeTrailingZeros(string num) {
        return num.substr(0, num.find_last_not_of('0') + 1);
        //find_last_not_of();该函数返回从字符串末尾开始不是X数的下标
        //sunstr()截取从下标[x,y)的字符串
    }
};