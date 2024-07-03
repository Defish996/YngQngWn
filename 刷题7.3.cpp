//哈得数

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int num = 0, y = x;
        while(x >= 10)
        {
            int tmp = x%10;
            num += tmp;
            x /= 10;
        }
        num += x;
        return y % num == 0 ? num : -1;
    }
};