// 1004. 最大连续1的个数 III 滑动窗口

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0;
        int zeroSum = 0;
        while(right < n)
        {
            if(nums[right] == 0)
            {
                ++zeroSum;
            }
            // if(zeroSum > k)
            // {
            //     ans = max(ans, right - left);
            //     left = right - 1;
            // }
            // 想法很好, 但是为什么不对?
            // 首先, 整个滑动窗口的思路是右值进窗口, 判断条件, 条件成立与否意味着是否可以更新结果
            // 那么在判断条件这里
            // 根据题意, 我们要进行一一判断, 不能省略某个数, 因为被替换的0可能在任意的某个窗口的位置
            // 所以只要进行窗口值的一一缩减, 也就是++left
            // 然后满足再次进窗口的条件, 也就是zero < k时即可
            // 所以上述的if可以这样写
            while(zeroSum > k)
            {
                if(nums[left++] == 0) --zeroSum;
            }
            // 此时可以根据right - left + 1来完成统计结果
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};