// leetcode 242. 有效的字母异位词 hash应用


class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26];
        for(auto &e : s)
        {
            hash[e - 'a']++;
        }
        for(auto &e : t)
        {
            hash[e - 'a']--;
        }
        for(auto &x : hash)
        {
            if(x != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// 二叉树中的节点个数 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;// 1为当前节点
    }
};

// leetcode 258. 各位相加
// 模拟法
class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
    all:
        while(num > 0)
        {
            ans += num % 10;
            num /= 10;
        }
        if(ans > 9)
        {
            num = ans;
            ans = 0;
            goto all; 
        }
        return ans;
    }
};
// 数学规律 同余定理的应用
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};


// leetcode LCR 083. 全排列

class Solution {
    vector<vector<int>> ret;// 存储结果
    vector<int> path;// 记录经过叶子路径后的值
    bool check[7];// 检查当前节点是否已经过遍历 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ret;
    }
    void dfs(vector<int> &nums)
    {
        if(nums.size() == path.size())// 当到达当前节点后的大小与nums的大小一样时, 表明是一种满足条件的方式, 进行返回
        {
            ret.push_back(path);// 返回前存储当前的结果
            return; 
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(check[i] == false)// 若当前的节点没有被使用, 则进行记录(判断是使用它的下标进行判断)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);// 当前节点判断结束之后, 就进行下一轮的递归
                // 下次函数调用时, 因为当前的值为false,所以不会进行存入, 循环到下个值进行dfs, 也就是会继续递归进入
                path.pop_back();// 进行回溯时恢复现场
                check[i] = false;
            }
        }

    }
};

 