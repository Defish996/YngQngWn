//leetcode 34. 在排序数组中查找元素的第一个和最后一个位置


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                vec.push_back(i);
            }
        }
        if(vec.size() == 1)
        {
            return vector<int>{vec[0], vec[0]};
        }
        else if(vec.size()==0)
        {
            return vector<int>{-1, -1};
        } 
        else
        {
            return vector<int>{vec[0], vec.back()};
        }
    }
};