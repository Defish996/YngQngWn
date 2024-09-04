// leetcode 3174. 清除数字 栈应用


class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string st;
        for(int i = 0; i < n; i++)
        {
            if(!isdigit(s[i]))
            {
                st += s[i];
            }
            else
            {
                st.pop_back();
            }
        }
        return st;
    }
};