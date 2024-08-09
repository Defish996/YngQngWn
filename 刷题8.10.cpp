// leetcode 63. 不同路径 II dp


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[1][0] = 1;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(obstacleGrid[i - 1][j - 1] == 0)// 无障碍物时, 可以进行路径相加
                                                   // 因为多开了一行一列, 所以实际原二维数组中的值是当前下标对应的前一个位置
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};