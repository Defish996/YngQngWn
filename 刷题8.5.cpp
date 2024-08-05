// leetcode 129. 求根节点到叶节点数字之和 递归 设计


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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);// 当前节点和在此节点之前的值
    }
    int dfs(TreeNode* root, int presum)
    {
        presum = presum *10 + root->val;// 1. 到达当前节点后, 在此处的值是什么: 上一次的值*10+当前的val
        if(root->left == nullptr && root->right == nullptr)// *递归出口: 为叶子节点, 返回已经计算的值
            return presum;
        int ret = 0;// 存储计算的结果
        if(root->left) ret += dfs(root->left, presum);// 2. 左根
        if(root->right) ret += dfs(root->right, presum); // 3. 右根
        return ret; // 4. 返回保存的结果
    }
};