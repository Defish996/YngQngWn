//leetcode 231. 2 的幂 

// 方法一 : set额外创建
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        unordered_set<int> st;
        long long num = 1;
        while(num <= INT_MAX)//将所有2的幂放入这个set
        {
            st.insert(num);
            num *= 2;
        }
        return st.count(n);//看这个n在不在这个set
    }
};

// 方法二 : 方法一迭代 在循环过程中进行判断
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long num = 1;
        while(true)
        {
            if(num == n) return true;
            if(num > n) break;
            num *= 2;
        }
        return false;
    }
};

//方法三 : 记录二进制中1的个数, 次数超过1就不是2的幂
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num = 0;//记录二进制中1的个数, 次数超过1就不是2的幂
        while (n > 0) {
            if (n & 1) { // 检查 n 的最低位是否为1
                num++;
            }
            n >>= 1; // 将 n 右移一位
        }
        return num == 1;
    }
};
//leetcode 283. 移动零 双指针

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n)
        {
            if(nums[right] != 0)//若为0, left停在0的位置, right继续向后找到非0, 然后进行交换
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
