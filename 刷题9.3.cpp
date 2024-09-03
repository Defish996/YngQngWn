// leetcode 两数之和 hash运用

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            auto it = map.find(target - nums[i]);// 找是否存在与当前值对应的合法条件的值
            if(it != map.end())
            {
                return {i, it->second};// 存在就返回当前下标和当前合法值的下标
            }

            map[nums[i]] = i;// 值与下标的键值对
        }
        return {};
    }
};