// 快乐数重现, 鸽巢原理(抽屉原理), 链表有无环的判定

class Solution {
public:
    int Sum(int n)// 得到一个数的结果为各个位的平方 eg: 68 结果为100  过程为6 * 6 + 8 * 8 = 100
    {
        int ans = 0;
        while(n > 0)
        {
            int tmp = n % 10;
            ans += tmp * tmp;
            n /= 10; 
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n, fast = Sum(n);// 初始化的值, 我们可以选择是n, 但是循环条件不能一样, 所以fast可以套一层, 但实际上, fast套几层都是可以的, 例fast = Sum(Sum(n)), 答案也是正确的
        while(slow != fast)
        {
            slow = Sum(slow);
            fast = Sum(Sum(fast));
        }
        return slow == 1;
    }
};


// 盛水最多的容器双指针定义两边, 哪边小哪边向内移动

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while(left < right)// 双指针定义两边, 哪边小哪边向内移动
        {
            int LVal = height[left], RVal = height[right];
            int hight = min(LVal, RVal);
            int length = right - left;
            ans = max(ans, hight * length);
            if(LVal <= RVal)
            {
                ++left;
            } 
            else
            {
                --right;
            }
        }
        return ans;
    }
};