// 438. 找到字符串中所有字母异位词 滑动窗口+hash


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int hash1[26] = { 0 };// 记录p中的hash数组情况
        for(auto & e : p)
        {
            hash1[e - 'a']++;
        }
        int hash2[26] = { 0 };
        int count = 0;// 引入一个变量, 该变量用于记录s存入hash2的有效个数, 这个有效个数是hash的key符合, 且key的val也符合(当val小于等于p的val时, 表明当前的key有可能使我们需要的)
        for(int left = 0, right = 0; right < s.size(); right++)
        {
            char in = s[right];
            if(++hash2[in - 'a'] <= hash1[in - 'a']) count++;// 统计hash个数, 同时进行有效的判断
            if(right - left + 1 > p.size()) // 窗口是固定的p的大小, 为什么不是p对应的hash.size()的大小?那样也可以, 但是根据后续的判定发现这种更好用
            {
                char out = s[left++];
                if(hash2[out - 'a']-- <= hash1[out - 'a']) count--;
            }
            if(count == p.size()) ans.push_back(left);
        }
        return ans;
    }
};