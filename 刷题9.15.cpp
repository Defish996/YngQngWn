// 1920. 基于排列构建数组 映射

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            ans.push_back(nums[nums[i]]);// 根据题目要求, 进行对应的映射关系
        }
        return ans;
    }
};