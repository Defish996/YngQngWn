// leetcode 1863. 找出所有子集的异或总和再求和 回溯+计数

class Solution {
    int path;
    int ans;
public:
    int subsetXORSum(vector<int>& nums) {
        // 与求子集的过程类似
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int> &nums, int pos)
    {
        ans += path;
        for(int i = pos; i < nums.size(); i++)// 每次遍历时因为不需要进行子集的存储, 但是又会遍历每个元素, 所以这一步就相当于在遍历子集, 遍历子集的时候, 就可以进行异或运算, 将异或的结果存到ans中
        {
            path ^= nums[i];
            dfs(nums, i + 1);
            path ^= nums[i];
            long long k = 0;
        }
        // 出口就是这个循环结束自动返回
    }
};

