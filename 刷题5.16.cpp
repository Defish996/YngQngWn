//leetcode 657. 机器人能否返回原点(练习pair的使用)

class Solution {
public:
    bool judgeCircle(string moves) {
    pair<char, int> map[4]= {{'R',0},{'L',0},{'U',0},{'D',0}};
    for(auto& e : moves)
    {
        if(e=='R') map[0].second++;
        else if(e=='L') map[1].second++;
        else if(e=='U') map[2].second++;
        else if(e=='D') map[3].second++;
    }
    return map[0].second==map[1].second&&map[2].second==map[3].second;
    }
};