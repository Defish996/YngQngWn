// 四数之和

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // for(auto & e : nums)
        // {
        //     cout << e << " ";
        // }
        // cout << endl;
        int a = 0;
        while(a <= n - 4)
        {
            int b = a + 1;
            while(b <= n - 3)
            {
                long long  tar = (long long)target - nums[a] - nums[b];
                int left = b + 1, right = n - 1;
                vector<int> ans;
                while(left < right)
                {
                    int LVal = nums[left], RVal = nums[right];
                    // cout << nums[a] << " " << nums[b] << " " <<LVal << " " << RVal << " " << tar << endl;
                    if(LVal + RVal == tar)
                    {
                        ans.push_back(LVal);
                        ans.push_back(RVal);
                        ans.push_back(nums[a]);
                        ans.push_back(nums[b]);
                        ret.push_back(ans);
                        // for(auto & e : ans)
                        // {
                        //     cout << e << " ";
                        // }
                        ans.clear();
                        while(nums[++left] == LVal && left < right);
                        while(nums[--right] == RVal && left < right);

                    }
                    else if(LVal + RVal < tar)
                    {
                        while(nums[++left] == LVal && left < right);
                    }
                    else
                    {
                        while(nums[--right] == RVal && left < right);
                    }
                }
                ++b;
                while(nums[b] == nums[b - 1] && b <= n - 3)
                {
                    ++b;
                }
            }
            ++a;
            while(nums[a] == nums[a - 1] && a <= n - 4)
            {
                ++a;
            }
        }
        return ret;
    }
};