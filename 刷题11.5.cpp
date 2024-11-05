// leetcode 3222. 求出硬币游戏的赢家
// 数学 + 博弈
class Solution {
public:
    string losingPlayer(int x, int y) {
        int num = 0;
        while(x >= 1 && y >= 4)
        {
            --x;
            y -= 4;
            ++num;
        }
        --num;
        return num % 2 == 0 ? "Alice" : "Bob";
    }
};

// 优化:
// 因为按照题意每次的--x, 对应着y -= 4;
// 那么这样就可以得到对局的总局数
// 局数为奇数, A赢 反之B赢
class Solution {
public:
    string losingPlayer(int x, int y) {
        return min(x, y/4) % 2 == 0 ? "Bob" : "Alice";
    }
};