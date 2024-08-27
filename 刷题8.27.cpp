// leetcode 242. 有效的字母异位词 hash应用


class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26];
        for(auto &e : s)
        {
            hash[e - 'a']++;
        }
        for(auto &e : t)
        {
            hash[e - 'a']--;
        }
        for(auto &x : hash)
        {
            if(x != 0)
            {
                return false;
            }
        }
        return true;
    }
};