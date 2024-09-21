// leetcode 有效三角形的个数

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum = n - 1, ans = 0;
        while(sum >= 2)
        {
            int left = 0, right = sum - 1;
            while(left < right)
            {
                if(nums[left] + nums[right] > nums[sum])
                {
                    ans += right - left;
                    --right;
                }
                else
                {
                    ++left;
                }
            }
            --sum;
        }
        return ans;
    }
};

// 和为s的两个数字
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right)
        {
            if(nums[left] + nums[right] < target)
            {
                ++left;
            }
            else if(nums[left] + nums[right] > target)
            {
                --right;
            }
            else{
                ans[0] = nums[left];
                ans[1] = nums[right];
                break;
            }
        }
        return ans;
    }
};