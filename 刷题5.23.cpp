//leetcode 2831. 找出最长等值子数组 hash+滑动窗口

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        //遍历利用hash将相同元素的下标进行存放
        //利用双指针对hash进行遍历,当得到的结果<=k时
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for(int i = 0; i < n; i++)//值和下标存入hash
        {
            pos[nums[i]].emplace_back(i);//hash的val是一个数组,存放的是key的下标
        }
        int ans = 0;//存储结果
        for(const auto&[_,vec] : pos)//滑动窗口实现
        {   
            //i表示右窗口,j为左窗口
            for(int i = 0, j = 0; i < vec.size(); i++)//i下标对vec遍历
            {
                while(vec[i]-vec[j]-(i-j) > k)//当要删除的数量大于k时,就需要缩小窗口，左窗口开始向右移动,vec[i] 到 vec[j]表示窗口的跨度,i-j为具有相同元素子数组的长度,即vec[i]-vec[j]-(i-j)为要删除的元素的数量
                {
                    j++;
                }
                ans = max(ans, i - j + 1);//更新最大子数组的长度
            }
            
            

        }
        return ans;

    }
};



//leetcode 169. 多数元素 hash+计数


class Solution {
public:
    int  majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans=0,cnt=0;
        for(const auto& e : nums)
        {
            map[e]++;
            if(map[e]>cnt)
            {
                cnt = map[e];
                ans = e;
            }
        }
        return ans;
    }
};