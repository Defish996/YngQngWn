// leetcode633. 平方数之和 

// 方法一: 数学
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a * a <= c; ++a)
        {
            double b = sqrt(c - a * a);
            if(b == (int)b)
            {
                return true;
            }
        }
        return false;
    }
};
