//leetcode 寻找重复数

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);//第一个循环找到相遇点

        slow = 0;//slow 从起点 0开始移动，fast从环内开始移动，相遇的点就是答案。
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
