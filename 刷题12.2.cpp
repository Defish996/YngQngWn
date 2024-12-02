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