// 数组相邻元素不能为奇偶性相同

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        for(int i = 1; i < nums.size(); i++)
        {   
            if(nums[i-1]%2 == nums[i]%2)
            {
                return false;
            }
        }
        return true;
    }
};