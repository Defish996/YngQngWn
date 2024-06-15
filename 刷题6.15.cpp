//2779. 数组的最大美丽值  排序+滑动窗口

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        //问题经过演化,判断条件也可以被看做是寻找当前区间内的在  左窗口和右窗口之间的数字不大于2k的个数,若大于就要调整窗口的大小
        //首分析发现排序对数组的结果没有影响,所以排序利用滑动窗口来解决这个问题
        sort(nums.begin(), nums.end());

        int n = nums.size(), left = 0, ans = 0;
        for(int right = 0; right < n; right++)//利用有窗口来遍历每个元素
        {
            while(nums[right] - nums[left] > 2 * k)//是否需要调整左窗口
            {
                ++left;
            }
            ans = max(ans, right - left + 1);//更新当前结果的最大值
        }
        return ans;
    }
};