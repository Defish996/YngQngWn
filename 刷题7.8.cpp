//1991. 找到数组的中间位置


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //方法一

        // int n = nums.size();
        // vector<int> vec(n+1, 0);
        // for(int i = 1; i <= n; i++)//前缀和放入比nums数组大1的vec中vec[0]为0,占位用
        // {
        //     vec[i] = vec[i - 1] + nums[i-1];
        // }
        // for(int i = 0; i < n; i++)//二次遍历找中间值
        // {
        //     if(vec[i] == vec[n]-vec[i+1])//当前值若==在总和中减去当前的下一个值,表明是当前就是那个中线下标
        //     {
        //         return i;
        //     }
        // }
        // return -1;

        //方法二

        int total = accumulate(nums.begin(), nums.end(), 0);//从begin到end求和加第三个参数的值,且这个参数不能省略
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(2 * sum + nums[i] == total)//回归题目,发现中间值的两倍加当前的num等于total
            {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};