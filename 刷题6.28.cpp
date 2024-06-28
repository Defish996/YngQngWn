//leetcode 35. 搜索插入位置 二分


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(target  > nums[mid])
            {
                left = mid + 1;
            }
            else 
            {
                right = mid - 1;
            }
        }
        return left;
    }
};