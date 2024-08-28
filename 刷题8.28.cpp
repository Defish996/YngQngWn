// leetcode 263. 丑数 数学问题


class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        vector<int> arr = {2, 3, 5};
        for(auto &e : arr)// 因为数组的值是按照顺序排列的, 且2 3 5 是自然数中, 能当除数的最小数, 从2开始的小数不能除尽的数, 只有后面的数才能除, 所以按照顺序遍历即可
        {
            while(n % e == 0)// 当这个数能被取模为0 的时候, 表明是1 或者是其他
                             // 因为1是满足的, 所以当是其他数的时候, 这个数因为不能一次性除尽, 所以要使用循环除除到结果为1, 然后又与1的判断结果一样
                             // 当这个数不能被取模为0时, 表示当前不是次数组的下标对应的倍数, 所以循环下一个数组的值, 直到所有的数都不满足, 此时当最终结果不是1, 表明没有被采取取模的操作, 这是不符合题意规定的, 所以不是丑数 
            {
                n /= e;
            }
        }
        return n == 1;
    }
};

//268. 丢失的数字 hash+计数

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1);
        for(auto &e : nums)
        {
            hash[e] = 1;
        }
        for(int i = 0; i <= n; i++)
        {
            if(hash[i] == 0)
            {
                return i; 
            }
        }
        return 0;
    }
};

// 278. 第一个错误的版本  二分
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid))
            {
                right = mid - 1;
            }
            else if(!isBadVersion(mid))
            {
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return left;
    }
};