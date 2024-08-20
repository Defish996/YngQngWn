// leetcode551. 学生出勤记录 I


class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int l = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'A') 
            {
                ++a;
                if(a == 2) return false;
            }
            if(s[i] == 'L') 
            {
                ++l;
                if(l == 3) return false;
            }
            else l = 0;
        }

        return true;
    }
};