// leetcode Nim游戏:博弈

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};