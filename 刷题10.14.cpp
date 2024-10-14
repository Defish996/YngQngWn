// 3158. 求出出现两次数字的 XOR 值 异或 hash


class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans = 0;
        for(auto & e : nums)
        {
            map[e]++;
            if(map[e] == 2)
            {
                ans = ans ^ e;
            }
        }
        return ans;
    }
};