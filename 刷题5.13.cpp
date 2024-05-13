//leetcode 994. 腐烂的橘子

class Solution {

private:
    vector<vector<int>> vec = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        // vector<vector<int>> map(n+1,vector<int>(m+1));

        for (int t = 3; t < n * m + 3; t++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == t - 1) {
                        for (int k = 0; k < 4; k++) {
                            int x = i + vec[k][0];
                            int y = j + vec[k][1];
                            if (x >= 0 && x < n && y >= 0 && y < m) {
                                if (grid[x][y] == 1) {
                                    grid[x][y] = t;
                                    ans = t - 2;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};