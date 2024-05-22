//leetcode 2225. 找出输掉零场或一场比赛的玩家

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> win;
        unordered_map<int, int> defeat;

        int leftSum = 0, rightSum = 0;
        for (const auto& e : matches)//需要掌握二维的两个维度怎么分别存放进hash表中
        {
            win[e[0]]++;
            defeat[e[1]]++;
        }
        vector<vector<int>> ans(2);
        for (const auto& player : win)
        {
        	//这个if需要掌握怎么看一个hash的key,在不在另一个hash的key里面
        	//还要看范围for遍历hash表时,怎么访问key和val
            if (defeat.find(player.first) == defeat.end())//在defeat中找win失败,返回defeat的end(),即win在defeat中不存在
            {
                ans[0].push_back(player.first);
            }
        }
        for (const auto& e : defeat)
        {
            if (e.second == 1)
            {
                ans[1].push_back(e.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());//对于二维数组的排序
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};