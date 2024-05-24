//leetcode 2903. 找出满足差值条件的下标 I 两层循环

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> vec{-1,-1};
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(abs(i-j)>=indexDifference&&abs(nums[i]-nums[j])>=valueDifference)
                {
                    vec[0] = i;
                    vec[1] = j;

                    return vec;

                }
            }
        }
        return vec;
    }
};