//leetcode 1103. 分糖果 II  模拟题 双百


class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int k = num_people, sum = candies;
        for(int i = 1;; i++)
        {
            int tmp = i % k;
            if(tmp == 0)
            {
                tmp = k;
            }

            if(sum < i)
            {
                ans[tmp - 1] += sum;
                break;
            }
            ans[tmp-1] += i;
            sum -= i;
            if(sum == 0) break;
        }
        return ans;
    }
};