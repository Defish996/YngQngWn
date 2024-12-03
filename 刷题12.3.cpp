// 寻找重复元素II 

// 方法一 找到存在hash, 然后再进行o(n^2)遍历找值
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < nums.size(); ++i)
        {
            map[nums[i]].push_back(i);
        }
        for(auto &e : map)
        {
            auto vec = e.second;
            int n = vec.size();
            if(n >= 2)
            {
                for(int i = 0; i < n; ++i)
                {
                    for(int j = i + 1; j < n; ++j)
                    {
                        if(abs(vec[i] - vec[j]) <= k)
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

//方法二 直接使用hash进行查找比较
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int i = 0; i < n; ++i)
        {
            if(map.count(nums[i]) && abs(i - map[nums[i]]) <= k)// hash存值和根据下标的升序性, 若前值减后一个值不存在<=k的值, 表明越往后这个值的差距只会越来越大, 更不可能<=, 所以利用这一点完成下标值的存放
            {
                return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};