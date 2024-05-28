//leetcode 2951. 找出峰值 简单题


class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> vec;
        for(int i = 1; i < mountain.size() - 1; i++)
        {
            if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) vec.push_back(i);
        }
        return vec;
    }
};