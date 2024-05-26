//leetcode 122. 买卖股票的最佳时机 II dp双百


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, price = prices[0];
        for(const auto& e : prices)
        {
            if(e <= price) 
            {
                price = e;
                continue;
            }
            else
            {
                ans += e - price;
                price = e;
            }
        }
        return ans;
    }
};

//leetcode 55. 跳跃游戏

//很巧妙的思路,有路就能走,当人走的步数大于路的长度,就false
//跳就完了
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};

//1738. 找出第 K 大的异或坐标值 前缀和+位运算


class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> vec;
        vector<vector<int>> sum(n+1,vector<int>(m+1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                sum[i][j] = sum[i-1][j] ^ sum[i][j-1] ^ sum[i-1][j-1] ^ matrix[i-1][j-1];
                vec.push_back(sum[i][j]);
            }
        }
        sort(vec.begin(),vec.end(),greater<int>());
        return vec[k-1]; 

    }
};
