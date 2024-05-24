//leetcode 1673. 找出最具竞争力的子序列  单调栈+贪心


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            while(!ans.empty()&&n-i+ans.size()>k&&ans.back()>nums[i])//遍历nunms的剩余元素+st内的个数>k时,进行删除操作
            {
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        }
        ans.resize(k);
        return ans;
    }
};