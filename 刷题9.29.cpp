// 2073. 买票需要的时间 一次遍历 模拟

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int n = tickets.size();
        int num = tickets[k];
        for(int i = 0; i < n; i++)
        {
            if(i <= k)
            {
                if(tickets[i] >= num)
                {
                    ans += num;
                }
                else{
                    ans += tickets[i];
                }
            }

            else if(i > k){
                if(tickets[i] >= num)
                {
                    ans += num - 1;
                }
                else{
                    ans += tickets[i];
                }
            }
        }
        return ans;
    }
};