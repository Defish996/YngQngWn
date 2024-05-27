//leetcode 2028. 找出缺失的观测数据 


class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans(n);
        int sum2 = rolls.size() + n;
        int sum = sum2 * mean;
        for(auto& e : rolls)
        {
            sum -= e;
        }
        if(sum > n*6) return vector<int> (0);
        int div = sum / n;
        if(div < 1) return vector<int> (0);
        int mod = sum % n;
        int i = 0;
        for(; i < n - mod; i++)
        {
            ans[i] = div;
        }
        div++;
        for(; i < n; i++)
        {
            ans[i] = div;
        }
        return ans;
    }
};