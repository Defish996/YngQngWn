//2965. 找出缺失和重复的数字   hash 的应用

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> map;
        for(const auto& e : grid)
        {
            for(const auto& t : e)
            {
                map[t]++;
            }
        }
        int a = 0, b = 0;
        for(int i = 1; i <= n * n; i++)
        {
            if(map[i] == 2) a = i;
            else if(map[i] == 0) b = i;//当访问这个不存在的值时,会自动进行添加值的操作,不过他的val是0,因为并没有进行val++的操作
        }
        return {a, b};

    }
};