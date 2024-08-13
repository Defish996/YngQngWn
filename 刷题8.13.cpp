// 数组相邻元素不能为奇偶性相同

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        for(int i = 1; i < nums.size(); i++)
        {   
            if(nums[i-1]%2 == nums[i]%2)
            {
                return false;
            }
        }
        return true;
    }
};

// leetcode 125. 验证回文串 双指针


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            while(left < right && !isalnum(s[left])) // 不是字母或数字,左右两边都跳过
            {
                ++left;
            }
            while(left < right && !isalnum(s[right]))
            {
                --right;
            }
            if(left < right) // 每次将指针移到下一个字母字符或数字字符，再判断这两个指针指向的字符是否相同
            {
                if(tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }
            }
            ++left;
            --right;   
        }
        return true;
    }
};