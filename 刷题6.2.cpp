//575. 分糖果 hash+模拟

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> map;
        for(auto& e : candyType)
        {
            map[e]++;
        }
        vector<pair<int, int>> vec(map.begin(), map.end());
        int n = vec.size();
        int num = candyType.size() / 2;
        return num < n ? num : n;
    }
};