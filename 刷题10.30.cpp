// 最小字典序 贪心

class Solution {
public:
    string getSmallestString(string s) {
        // 按照题意 最多交换一次, 可以交换次数为0 或者1
        // 要得到最小字典序, 所以交换的值越左边越好
        // 得到最小, 所以交换后的值一定比原先的值严格小于, 所以一定是左边大于右边
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i - 1] > s[i] && s[i - 1] % 2 == s[i] % 2)// 字符串对应的数字奇偶性, 就是ascii的奇偶性
            {
                swap(s[i], s[i - 1]);
                break;
            }
        }
        return s;
    }
};