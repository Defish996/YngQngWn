// 无重复元素的最长子串 滑动窗口

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int ans = 0;
        // unordered_map<char, int> map;
        // 优化, 因为s 由英文字母、数字、符号和空格组成, 所以可以使用0-128来表示
        int map[128] = {0};
        while(right < n)// 右窗口到达数组边界, 意味着子串判定结束
        {
            map[s[right]]++;// 1. hash进窗口
            while(map[s[right]] > 1)// 2.当有重复元素时
            {
                map[s[left++]]--;  // 将这个窗口一一向左移动, 直到移去那个重复的元素 
            }
            ans = max(ans, right - left + 1);// 2.无重复元素时判断当前窗口的大小, 删除重复元素后也进行判断,但实际是变小的, 不影响
            ++right;// 3.窗口向右移动,让下一个元素进入窗口
        }
        return ans;
    }
};