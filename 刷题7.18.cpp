//91,解码方式 dp思路到优化

// class Solution {
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n, 0);
//         //dp[i]表示到达i位置时的解码方式,依次为终点, 进行dp思考
//         dp[0] = s[0] != '0';//不为0就是为真, 为1
//         //if(dp[0] == 1) return 0;
//         if(n == 1) return dp[0];//边界
//         if(s[0] != '0' && s[1] != '0' ) dp[1] = 1;//两个都能单独解码
//         int t = (s[0] - '0') * 10 + s[1] - '0';
//         if(10 <= t && t <= 26) dp[1] += 1;//合一起也能解码
//         for(int i = 2; i < n; i++)
//         {
//             if(s[i] != '0') dp[i] += dp[i - 1];//单独
//             t = (s[i - 1] - '0') * 10 + s[i] - '0';
//             if(10 <= t && t <= 26) dp[i] += dp[i - 2];//合一起
//         }
//         return dp[n - 1];
//     }
//}; 
//优化后
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;//根据题意可知
        dp[1] = s[0] != '0';
        for(int i = 2; i <= n; i++)
        {
            if(s[i - 1] != '0') dp[i] += dp[i - 1];//单独
            int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if(10 <= t && t <= 26) dp[i] += dp[i - 2];//合一起
        }
        return dp[n];
    }
};