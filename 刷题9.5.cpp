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

// 509. 斐波那契数 dp


class Solution {
public:
    int fib(int n) {
        if(n < 2)
        {
            return n;
        }
        int l = 0, r = 1, x = 1;
        for(int i = 2; i < n; i++)
        {
            l = r;
            r = x;
            x = r + l;
        }
        return x;
    }
};