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