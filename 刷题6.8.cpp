//832. 翻转图像  模拟题

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size(), n = image.size();
        int tmpn = n - 1, tmpm = m - 1;
        vector<vector<int>> map(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            tmpn = n - 1;
            for(int j = 0; j < n; j++)
            {
                map[i][tmpn--] = image[i][j];
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(map[i][j] == 1)
                {
                    map[i][j] = 0;
                }
                else
                {
                    map[i][j] = 1;
                }
            }
        }
        return map;
    }
};