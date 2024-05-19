//leetcode //2644. 找出可整除性得分最大的整数

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        pair<int, int> ans;
        int min = 1e9;
        for(int i = 0;i < divisors.size(); i++)
        {
            int tmp = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[j]%divisors[i]==0)
                {
                    tmp++;
                }
            }
            if(tmp > ans.first || (tmp == ans.first && ans.second > divisors[i]))
            {
                ans.first = tmp;
                ans.second = divisors[i];
            }
            if(divisors[i]<min)
            {
                min = divisors[i];
            }
        }
        if(ans.first == 0) return min;
        return ans.second;
    }
};