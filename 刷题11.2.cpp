// 3226. 使两个整数相等的位更改次数 位运算

class Solution {
public:
    int minChanges(int n, int k) {
        if(k == n) return 0;
        int ans = 0;
        while(n != 0 || k != 0)
        {   
            int tmp1 = k & 1; 
            int tmp2 = n & 1; 
            if(tmp2 != tmp1)
            {
                if(tmp2 == 0)
                {
                    return -1;
                }
                ++ans;
            }
            k >>= 1;
            n >>= 1;
        }
        return ans;
    }
};