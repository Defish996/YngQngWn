// 二分查找寻找两数之和 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right)
        {
            int num = numbers[left] + numbers[right];
            if(num == target)
            {
                return {left, right};
            }
            else if(num < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return {};
    }
};

//dp 爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};