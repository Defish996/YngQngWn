//520. 检测大写字母 lambda + isupper() C++20 ranges库内count_if使用

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = ranges::count_if(word, [](char c){return isupper(c);});
        return n == 0 || n == word.size() || n == 1 && isupper(word[0]);
    }
};