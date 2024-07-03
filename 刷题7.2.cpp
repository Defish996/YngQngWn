//leetcode 860. 柠檬水找零 贪心思想小体现,模拟套皮贪心

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        if(bills[0] != 5) return false;
        for(auto &x : bills)
        {
            if(x == 5)
            {
                five++;
            }
            else if(five == 0)
            {
                return false;
            }
            else
            {
                if(x == 10)
                {
                    five--;
                    ten++;
                }
                else
                {
                    if(ten != 0)//贪心体现
                    {
                        ten--;
                        five--;
                    }
                    else
                    {
                        five -= 3;
                    }
                    if(five<0) return false;
                }
            }
        }
        return true;
    }
};
//leetcode 3115. 质数的最大距离 质数o(N) 模拟


class Solution {
public:
    int m, n;
    bool isPrime(int n) 
    {  
        if (n <= 1) return false;  
        for (int i = 2; i <= sqrt(n); ++i) {  
            if (n % i == 0) return false;  
        }  
        return true;  
    }
    int maximumPrimeDifference(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(isPrime(nums[i]))
            {
                m = i;
                break;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(isPrime(nums[i]))
            {
                n = i;
                break;
            }   
        }
        if(m == 0 && n == 0)
        {
            return 0;
        }
        else
        {
            return n - m;
        }
    }
};