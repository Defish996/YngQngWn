// 290. 单词规律 hash双向映射

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        int i = 0;
        int j = 0;
        while(i < pattern.size())
        {
            char c = pattern[i];
            string word;
            while(s[j] != ' ' && j < s.size())
            {
                word += s[j++];
            }
            if(map1.find(c) != map1.end() && map1[c] != word || map2.find(word) != map2.end() && map2[word] != c)
            {
                return false;
            }
            map1[c] = word;
            map2[word] = c;
            j++;
            i++;
        }
        cout << j << "size: " << s.size();
        if(j != s.size() + 1) return false;
        return true;
    }
};