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