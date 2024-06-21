//LCP 61. 气温变化趋势  <=>的使用

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int n = temperatureA.size() - 1;
        int ans = 0, tmp = 0;
        for(int i = 0; i < n; i++)
        {
            auto a = temperatureA[i] <=> temperatureA[i+1];
            auto b = temperatureB[i] <=> temperatureB[i+1];
            if(a == b)
            {
                tmp++;
            }
            else
            {
                ans = max(ans, tmp);
                tmp = 0;
            }   
        }
        ans = max(ans, tmp); 
        return ans;
    }
};