//2129. 将标题首字母大写 大小写转化是32 好久没有都忘记了


class Solution {
public:
    string capitalizeTitle(string title) {
        int size = title.size(), i = 0;
        string s, word;
        while(i < size)
        {
            s += title[i];
            if(title[i] == ' '||i == size - 1)
            {
                if(i != size - 1)
                {
                    s.pop_back();
                }
                if(s.size()>=3)
                {   
                    if(s[0] >= 97 && s[0] <= 122)
                    {
                        s[0] -= 32;
                    }
                    for(int i = 1; i < s.size(); i++)
                    {
                        if(s[i] >= 65 && s[i] <= 90)
                        {
                            s[i] += 32;
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < s.size(); i++)
                    {
                        if(s[i] >= 65 && s[i] <= 90)
                        {
                            s[i] += 32;
                        }
                    }
                }
                word += s + ' ';
                s.clear();
            }
            i++;
        }
        word.pop_back();
        return word;
    }
};

//2917. 找出数组中的 K-or 值 位运算


class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < 31; i++)
        {
            int x = 0;
            for(int& num : nums)
            {
                if((num >> i) & 1)//将这数右移到第 i 位与1进行按位与(都为1,才是1)
                {                 //这个值第i位为1,继续下一个,由此循环结束第一个数第i位的判断
                    ++x;
                }
            }
            if(x >= k)//若共有>=k个的第i位都为1,则满足题目要求
            {
                ans |= 1 << i;//将1左移i位,与原先的值进行按位或(有1就是1),循环得到最终值
            }
        }
        return ans;
    }
};