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

// 219. 存在重复元素 II


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int x) {
        unordered_map<int, vector<int>> map;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            map[nums[i]].push_back(i);
            if(map[nums[i]].size() >= 2)
            {
                for(int j = 0; j < map[nums[i]].size(); j++)
                {
                    for(int k = j + 1; k < map[nums[i]].size(); k++)
                    {
                        if(abs(map[nums[i]][j] - map[nums[i]][k]) <= x)
                        {   
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

// 优化版本
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(map.count(nums[i]))
            {
                if(i - map[nums[i]] <= k)
                {
                    return true;
                }
            }
            map[nums[i]] = i;
        }
        return false;
    }
};