// 1436. 旅行终点站 unordered_set使用
// 结果一定在B的位置处, 所以遍历所有的A, 存到一个set中
// 然后遍历B, 看这个B在不在, 如果不在就说明是终点站


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> suma;
        for(auto & path : paths)
        {
            suma.insert(path[0]);// 存A
        }
        for(int i = 0; i < paths.size(); ++i)
        {
            if(!suma.count(paths[i][1]))// 找B是否在A, 不在, 这个B就是终点
            {
                return paths[i][1];
            }
        }
        return "";
    }
};