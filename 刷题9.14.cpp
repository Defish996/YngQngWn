// 2390. 从字符串中移除星号 栈的使用

class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto &e : s)
        {
            if(e == '*')
            {
                ans.pop_back();
            }
            else
            {
                ans += e;
            }
        }
        return ans;
    }
};