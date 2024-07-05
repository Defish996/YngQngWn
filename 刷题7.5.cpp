//leetcode 今日水题

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> vec(n);
        for(int i = 0; i < n; i++)
        {
            int tmp = -2;
            for(int j = 0; j < m; j++)
            {
                tmp = max(tmp, matrix[j][i]);
            }
            vec[i] = tmp;
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[j][i] == -1)
                {
                    ans[j][i] = vec[i];
                }
                else
                {
                    ans[j][i] = matrix[j][i];
                }
            }
        }
        return ans;
    }
};