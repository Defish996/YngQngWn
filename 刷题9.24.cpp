// 滑动窗口, 长度最小的子数组复习

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int ans = INT_MAX;
        int sum = 0;
        while(right < n)// 右窗口样小于数组边界
        {
            sum += nums[right];// 每次记录结果, 看结果是否满足题目要求
            while(sum >= target)// 满足表明可以执行对应的操作, 为什么是while呢? 当前一个right表示的值较大时, 可能减去一个左边界的值(在这个循环内部实现)就已经满足题目要求了, 所以使用while再次进行循环判断
            {   
                ans = min(ans, right - left + 1);// 在上次窗口和当前窗口选个小的
                sum -= nums[left];// 窗口左边界向左移, 同时左边界移动之前减去那个位置的值
                ++left;// 向左移动
            }
            ++right;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};