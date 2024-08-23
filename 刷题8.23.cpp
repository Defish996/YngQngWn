// leetcode 58. 最后一个单词的长度


class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                while(i >= 0 && s[i] != ' ')
                {
                    ans++;
                    i--;
                }
                break;
            }
        }
        return ans;
    }
};