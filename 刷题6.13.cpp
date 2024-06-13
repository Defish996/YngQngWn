//238. 除自身以外数组的乘积

//version_1  左前缀*右前缀得到ans
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> L(size), R(size);
        L[0] = 1;
        for(int i = 1; i < size; i++)
        {
            L[i] = L[i - 1] * nums[i - 1];
        }
        R[size - 1] = 1;
        for(int i = size - 2; i >= 0; i--)
        {
            R[i] = R[i + 1] * nums[i + 1];
        }
        for(int i = 0; i < size; i++)
        {
            L[i] = L[i] * R[i];
        }
        return L;
    }
};

//version_2 对version_1的优化,将空间复杂度优化为O(1),时间复杂度还是O(N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);
        ans[0] = 1;
        for(int i = 1; i < size; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int r = 1;
        for(int i = size - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * r;

            r *= nums[i];
        }
        return ans;
    }
};