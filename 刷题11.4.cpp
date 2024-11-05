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

// 方法二 双指针+数学
class Solution {
public:
    bool judgeSquareSum(int c) {
        // 假设a = 0, b = 根号c, 则一定有a*a + b*b = c; // 这样的假设不失一般性的数据的a*a + b*b = c * c的判断
        // 那么这样的假设会使满足题意的结果变为a*a + b*b = c, 当a*a + b*b < c时, 需要扩大化, 反之则要缩小, 看代码
        long a = 0;
        long b = (int)sqrt(c);// 万一开方是一个小数, 转为整数不影响对结果的判断
        while(a <= b)
        {
            long sum = a * a + b * b;
            if(sum == c) return true;
            else if(sum > c) --b;
            else ++a;
        }
        return false;
    }
};