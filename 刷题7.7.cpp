//leetcode 3101. 交替子数组计数 数学模拟找规律

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int cnt;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] != nums[i - 1])//当前与前一个不相等就可以成为子数组
            {
                ++cnt;
            }
            else//否则,从当前开始重新记数
            {
                cnt = 1;
            }
            ans += cnt;//满足最长的子数组的可以构成子数组的数目(有序个数n个字符, 可以组成n个子数组)
        }
        return ans;
    }
};