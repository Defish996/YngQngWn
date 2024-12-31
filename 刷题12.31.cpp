// 1190 反转每对括号间的子串


class Solution {
public:
    string reverseParentheses(string s) {
        string str;// 存放临时字符串    
        stack<string> stk;// 存放完整() 前的字符串
        for(auto &e : s)// 遍历字符串 分类讨论
        {
            if(e == '(')// (前的进栈 然后置空
            {
                stk.push(str);
                str = "";
            }
            else if(e == ')')// )后的实际操作:逆置 重新存放在tmp
            {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            }
            else{
                str.push_back(e);
            }
        }
        return str;
    }
};