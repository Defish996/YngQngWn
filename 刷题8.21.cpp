// 151. 反转字符串中的单词


class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> vec;
        string word;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ' ')
            {
                word.push_back(s[i]);
            }
            else if(s[i] == ' ' && !word.empty())
            {
                vec.push_back(word);
                word.clear();
            }
        }
        if(!word.empty())
        {
            vec.push_back(word);
            word.clear();
        }
        reverse(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); i++)
        {
            word += vec[i];
            word += ' ';
        }
        word.pop_back();
        return word;
    }
};