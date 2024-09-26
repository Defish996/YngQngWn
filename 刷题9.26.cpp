// 数组元素和与数字和的绝对差 leetcode每日一题 

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= 9)
            {
                sum += nums[i];
            }
            else
            {
                int tmp = nums[i];
                while(tmp > 0)
                {
                    sum += tmp % 10;
                    tmp /= 10;
                }
            }
            ans += nums[i];
        }
        return abs(ans - sum);
    }
};