// 414. 第三大的数,不存在就返回最大 计数+数学


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for(auto &num : nums)
        {
            if(num > a)
            {
                c = b;
                b = a;
                a = num;
            }
            else if(num > b && num < a)
            {
                c = b;
                b = num;
            }
            else if(num > c && num < b)
            {
                c = num;
            }
        }
        return c == LONG_MIN ? a : c;// 第三大数不存在就返回最大的
    }
};