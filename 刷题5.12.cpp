//两道简单的dp问题
//leetcode1137. 第 N 个泰波那契数
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        int a = 0, b = 1, c = 1, d = 0;
        for(int i = 3;i<=n;i++)
        {
            d = a + b + c;
            a = b, b = c, c = d;
        }
        return d;
    }
};

//leetcodeLCR 126. 斐波那契数
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1);
        if(n==0) return 0;
        if(n==1) return 1;
        dp[0] = 0;
        dp[1] = 1;
        const int MOD = 1e9+7;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        } 
        return dp[n];
    }
};

//leetcode70. 爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i <= n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};