// 17. 电话号码的字母组合 , dfs

class Solution {
    string hash[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string path;
    vector<string> ret;
public:
    vector<string> letterCombinations(string digits) {
        // 1. 搞定映射关系
        // 2. path记录结果的过程
        // 3. 记录节点的结果
        if(digits.size() == 0) return ret;
        dfs(digits, 0);
        return ret;
    }
    void dfs(const string &digits, int pos)
    {
        if(digits.size() == path.size())
        {
            ret.push_back(path);
            return;
        }
        for(auto e : hash[digits[pos] - '0'])
        {
            path.push_back(e);
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }
};