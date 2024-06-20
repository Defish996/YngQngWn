//2748. 美丽下标对的数目


class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                while(nums[i]>=10)
                {
                    nums[i]/=10;
                }
                if(gcd(nums[i], nums[j]%10) == 1)
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
};