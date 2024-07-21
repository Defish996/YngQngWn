//leetcode 53. 最大子数组和 子数组dp问题


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //分为两部分, 一部分是当前就是最大,另一部分是当前位置加之前的总和最大
        int n = nums.size(), ans = INT_MIN;
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++)
        {
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};