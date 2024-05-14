//leetcode 2244. 完成所有任务需要的最少轮数

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;//创建一个hash表来存放每一个值都会出现的次数
        for(const auto& t : tasks)//循环将hash填满
        {
            ++cnt[t];
        }
        int ans = 0;
        for(const auto& [_, e] : cnt)
        {
            if(e==1) return -1;
            else ans += e / 3 + (e % 3 != 0);
        }
        return ans;
    }
};