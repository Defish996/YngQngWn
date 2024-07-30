//leetcode 349. 两个数组的交集 unordered_set使用, 数组hash使用

//方法一 unordered_set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;//用于存放遍历后的结果
        unordered_set<int> numbers(nums1.begin(), nums1.end());//利用set性质初始化nums1
        for(int i = 0; i < nums2.size(); i++)//将nums2的元素与nums1内的元素进行比较
        {
            if(numbers.find(nums2[i])!=numbers.end())//如果存在, 就将元素放入result(set自动去重)
            {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());//将结果初始化为vector返回
    }
};

//方法二 数组
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;//存放结果
        int hash[1001]{0};//存放nums1的集合
        for(int i = 0; i < nums1.size(); i++)//填充hash
        {
            hash[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++)//对nums2进行映射判断
        {
            if(hash[nums2[i]] == 1)
            {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
