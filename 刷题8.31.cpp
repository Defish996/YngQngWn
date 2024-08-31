// 383. 赎金信+hash应用

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26);
        for(auto &e : magazine)
        {
            hash[e - 'a']++;
        }
        for(auto &e : ransomNote)
        {
            if(hash[e - 'a'] == 0)
            {
                return false;
            }
            else
            {
                hash[e - 'a']--;
            }
        }
        return true;
    }
};

// 205. 同构字符串 hash双向映射

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 本题是关于char与char之间的映射关系, 所以在添加之前看是否已添加映射, 若存在, 就需要判断当前的字符对应的映射是否满足双向映射, 否则进行添加
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            char a = s[i], b = t[i];
            if(map1.find(a) != map1.end() && map1[a] != b || map2.find(b) != map2.end() && map2[b] != a)// s向t映射的检查, t向s也需要检查
            {
                return false;
            }
            map1[a] = b;
            map2[b] = a;
        }
        return true;
    }
};