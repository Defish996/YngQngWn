//leetcode 26 删除有序数组中的重复项 双指针

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;
        while(right < nums.size())
        {
            if(nums[left] != nums[right])
            {
                nums[++left] = nums[right];

            }
            right++;
        }
        return left + 1;
    }
};
