// 128. 最长连续序列 hash


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &e : nums)
        {
            set.insert(e);
        }// 放入set

        int max_len = 0;
        for(const int & e : set)
        {
            if(!set.count(e - 1))// 前一个不在就说明需要进行遍历, 如果在, 说明已经在前一个之前的元素的遍历中已经处理过了
            {
                int len = 1;
                int curnum = e;
                while(set.count(curnum + 1))// 找当前的下一个在不在
                {
                    ++len;
                    ++curnum;
                }
                max_len = max(len, max_len);// 不在就进行当前与历史的最大len
            }
        }
        return max_len;
    }
};