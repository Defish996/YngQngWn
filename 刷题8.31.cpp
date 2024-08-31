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