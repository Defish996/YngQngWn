//13. 罗马数字转整数 了解罗马数规则

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap
        {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(i < s.size() - 1 && romanMap[s[i]] < romanMap[s[i+1]])//前一个小于后一个,减去当前,遍历到后一个时,加上后面的,虽然题意只有6种情况,但是其余几种都是相减后的折半,结果是一样的
            {
                ans -= romanMap[s[i]];
            }
            else
            {
                ans += romanMap[s[i]];
            }
        }
        return ans;
    }
};

//14. 最长公共前缀

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //C++ 标准库提供了很多处理字典序的函数。常用的函数包括 sort、lower_bound、upper_bound 等，它们默认使用字典序
        sort(strs.begin(), strs.end());
        string s1 = strs.front();
        string s2 = strs.back();
        for(int i = 0; i < s1.size(); i++)
        {
            if(i == s1.size() || s1[i] != s2[i])
            {
                return s1.substr(0, i);

            }
        }
        return s1;
    }
};