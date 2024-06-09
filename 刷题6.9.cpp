//45. 跳跃游戏 II 贪心思想的实现

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] == 0) return 0;
        int fastest = 0, current = 0, jumps = 0;
        for(int i = 0; i < n - 1; i++)
        {
            fastest = max(fastest, i + nums[i]);//得到最远距离
            if(i == current)//如果当前步数到达当前步数能到达的最远距离则需要进行跳一步和更改当前步数的最远举例
            {
                current = fastest;
                jumps++;
            }a
        }
        return jumps;
    }
};