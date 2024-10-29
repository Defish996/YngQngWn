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

// 方法2
// 位运算
vector<string> ans;
int n = 0;
cin >> n;
int mask = (1 << n) - 1;// 构造全1的n位二进制数
int x = 1 << n;// 表示2^n
for (int i = 0; i < x; ++i)// 在0 ~~ x-1 中筛选
{
	if (((i >> 1) & i) == 0)// 当前值与右移一位的值进行与运算，如果结果为0，则说明当前值没有连续的1交替出现，符合要求
	{
		ans.push_back(bitset<18>(i ^ mask).to_string().substr(18 - n));//取反得到原先的二进制表示，再取子串
	}
}
for (auto& x : ans)
{
	cout << x << endl;
}