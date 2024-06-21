//数字转字符串 时空复杂度都为O(N)

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// 时间复杂度为O(N) 空间复杂度为O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        // 负数和除0以外以0结尾的数都不是回文数
        //0本身被认为是回文数
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        // 回文数即使是奇数位，中间一位无关紧要
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
