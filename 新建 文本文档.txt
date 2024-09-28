// 1658. 将 x 减到 0 的最小操作数 逆向思维应用


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int left = 0, right = 0;
        int ans = -1/*小细节, 当未来在判断循环出去之后, 若没有满足的结果, 则结果就是-1*/, sum = 0;
        for(auto &e : nums) sum += e;
        if(sum < x) return -1;// 防止[1, 1] 3这样的示例
        int target = sum - x; 
        sum = 0;
        while(right < n)
        {
            sum += nums[right];
            while(sum > target)
            {
                sum -= nums[left++];
            }
            // ans = max(ans, right - left + 1);
            // 为什么不能这样写, 因为这样的操作导致忽略了题目反意的从左边开始, 找sum-x的区间最大的是几
            // 也就是相等才能存值
            // 当出窗口条件满足后, 并不意味着满足存值的结果, 我们的思路是为了得到答案, 所以最终应该是以结果为导向
            // 存值和判断的出有关系但不是必然
            if(sum == target)
            {
                ans = max(ans, right - left + 1);
            }
            ++right;
        }
        return ans == -1 ? ans : n - ans;// 按反向思路解题, 最后要将结果回正
    }
};