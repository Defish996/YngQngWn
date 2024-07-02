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