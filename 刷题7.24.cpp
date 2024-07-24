//leetcode 704. 二分查找

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)//左臂右臂区间[1,1]
        {
            int mid = (left + right) / 2;
            if(nums[mid] > target)//已经大于了, 证明是不包含该点, 所以去除该mid点
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }

        }
        return -1;
    }
};