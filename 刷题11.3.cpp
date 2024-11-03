// leetcode 22.括号生成 dfs 剪枝

class Solution {
    int left, right, n;
    vector<string> ans;
    string path;
public:
    vector<string> generateParenthesis(int _n) {
        n = _n;
        dfs();
        return ans;
    }
    void dfs()
    {
        if(right == n)// 出口
        {
            ans.push_back(path);
            return;
        }
        if(left < n)// 添加左括号的条件(利用剪枝进行递归操作)
        {
            path.push_back('(');
            ++left;
            dfs();
            path.pop_back();
            --left;
        }
        if(right < left)// 添加右括号的条件
        {
            path.push_back(')');
            ++right;
            dfs();
            path.pop_back();
            --right;
        }
    }
};