//leetcode2960. 统计已测试设备


class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for(int i = 0; i < batteryPercentages.size(); i++)
        {
            if(batteryPercentages[i] > ans)
            {
                ++ans;
            }
        }
        return ans;
    }
};