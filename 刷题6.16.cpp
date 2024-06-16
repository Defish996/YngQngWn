//134. 加油站 贪心+数组

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        //从起点开始遍历,存储总的gas-cost,保障油量必须大于消耗,这样才能走完一周,否则不能
        //然后存储当前的gas-cost,看是否有足够油量用来经过当前加油站
        int totalSum = 0;//总剩余余量
        int curSum = 0;//当前加油站的油量
        int point = 0;//可能的开始站点
        for(int i = 0; i < gas.size(); i++)//从第一个加油站尝试作为起始点来开车
        {
            totalSum += gas[i] - cost[i];
            curSum += gas[i] - cost[i];

            if(curSum < 0)
            {             
                point = i + 1;//小于0,说明是不能到达i + 1(当前加油站的下一个加油站点),所以要将加油站的起始点换为当前站点的下一个
                curSum = 0;
            }
        }
        if(totalSum < 0)
        {
            return -1;
        }
        return point;
    }
};

//521. 最长特殊序列 Ⅰ


class Solution {
public:
    int findLUSlength(string a, string b) {
        return a==b? -1 : max(b.size(), a.size());
    }
};