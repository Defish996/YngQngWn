//3211. 生成不含相邻零的二进制字符串 方法一 回溯深搜 

class Solution {
public:
    vector<string> validStrings(int n) {
   	vector<string> ans;
	string str;

	function<void(string&)> dfs = [&](string& str)
		{
			if (str.size() == n)
			{
				ans.push_back(str);
				return;
			}
			if (str.empty() || str.back() == '1')
			{
				str.push_back('0');
				dfs(str);
				str.pop_back();
			}
			str.push_back('1');
			dfs(str);
			str.pop_back();
		};
	dfs(str);
    return ans;
    }
};