// leetcode 191. 位1的个数 位运算

class Solution {
public:
    int hammingWeight(int n) {
        long long int ans = 0;
        while(n)
        {
            if(n & 1)
            {
                ++ans;
            }
            n >>= 1;
        }
        return ans;
    }
};

// 392. 判断子序列 一次遍历O(N)


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int i = 0;
        for(auto &c : t)
        {
            if(s[i] == c && ++i == s.size())
            {
                return true;
            }     
        }
        return false;
    }
};