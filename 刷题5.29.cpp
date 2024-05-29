//leetcode 2085. 统计出现过一次的公共字符串 hash


class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> map;
        int ans = 0;
        for(auto& e : words1)
        {
            map[e]++;
        }
        unordered_map<string, int> map2;
        for(auto& e : words2)
        {
            if(map.find(e) != map.end()) 
            {
                if(map[e] == 1)
                {
                    map2[e]++;
                }
            }
        }
        for(auto& e : words2)
        {
            if(map2.find(e) != map2.end() && map2[e] == 1)
            {
                ans++;
            }
        }
        return ans;
    }
};