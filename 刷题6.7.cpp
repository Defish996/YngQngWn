//leetcode 3038. 相同分数的最大操作数目 I 模拟双百



class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sum = nums[0] + nums[1], ans = 1;
        for(int i = 2; i < nums.size() - 1; i++)
        {
            if(nums[i] + nums[i++ + 1] == sum) ans++;
            else break;
        }
        return ans;
    }
};