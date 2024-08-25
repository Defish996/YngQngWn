// leetcode 217. 存在重复元素

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(auto &x : nums)
        {
            map[x]++;
            if(map[x] >= 2)
            {
                return true;
            }
        }
        return false;
    }
};
