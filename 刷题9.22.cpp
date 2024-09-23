// 三数之和, 先固定一个值, 让另外两数之和等于该数的相反数, 注意这个过程中的去重和避免遗漏(左右指针去重, target也要去重), 还有边界问题

// 代码中的打印信息导致编译器IO负担过大, 因此导致测试不通过, 所以在提交时最好做到注释打印内容
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(auto & e : nums)
        {
            cout << e << " ";
        }
        cout << endl;
        int n = nums.size();
        int target = 0;
        while(target <= n - 3)
        {
            int left = target + 1, right = n - 1;
            if(nums[target] > 0) break;// 优化
            vector<int> ans;
            while(left < right)
            {
                int LVal = nums[left], RVal = nums[right], tar = nums[target];
                // cout << LVal << " " << RVal << " " << nums[target] <<endl;
                // cout << endl;
                // if(LVal + RVal == -nums[target])
                // {
                //     cout << "if(LVal + RVal == -nums[target])" << endl;
                // }
                if(LVal + RVal == -nums[target])
                {
                    ans.push_back(LVal);
                    ans.push_back(RVal);
                    ans.push_back(nums[target]);
                    ret.push_back(ans);
                    ans.clear();
                    // cout << "ans :" << left << " " << right << " " << target << endl;
                    //因为得到结果之后可能还存在除对当前值的结果的和为0的情况, 所以不能省略                    
                    while(nums[++left] == LVal && left < right);
                    while(nums[--right] == RVal && left < right);

                }
                else if(LVal + RVal < -nums[target])
                {
                    while(nums[++left] == LVal && left < right);
                }
                else // LVal + RVal > -nums[target], 
                {
                    while(nums[--right] == RVal && left < right);
                }
            }
            ++target;
            while(nums[target - 1] == nums[target] && target <= n - 3)
            {
                ++target;
            }
        }
        return ret;
    }
};