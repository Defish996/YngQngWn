//leetcode 80. 删除有序数组中的重复项 II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int slow = 2, fast = 2;
        while(fast < n)
        {
            if(nums[slow-2] != nums[fast])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
//leetcode 169.对数元素
class Solution {
public:
    int  majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans,cnt;
        for(const auto& e : nums)
        {
            map[e]++;
            if(map[e]>cnt)
            {
                cnt = map[e];
                ans = e;
            }
        }
        return ans;
    }
};