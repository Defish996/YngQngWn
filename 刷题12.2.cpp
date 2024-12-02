// 357. 统计各位数字都不同的数字个数 排列组合问题+数学规律
 

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int cur = 9;
        int ans = 10;
        for(int i = 0; i < n - 1; ++i)// 一定是从第二位开始统计的
        {
            cur *= 9 - i;// 每一位的结果乘以之前的可能的组合数
            ans += cur;// 进行累加得出结果
        }
        return ans;
    }
};


// 两数之和 找出有序数组的序号, 二分

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right)
        {
            int num = numbers[left] + numbers[right];
            if(num == target)
            {
                return {left + 1, right + 1};
            }
            else if(num < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return {};
    }
};
// 判断能否赢得游戏  数学策略


class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for(auto &e : nums)
        {
            if(e <= 9)
            {
                sum1 += e;
            }
            else
            {
                sum2 += e;
            }
        }
        return sum1 == sum2 ? 0 : 1;
    }
};