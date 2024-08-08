//leetcode二叉搜索树中第K小的元素


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
    int count;
    int ret;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* root) 
    {
        if(root == nullptr) return;
        dfs(root->left);
        count--;
        if(count == 0) ret = root->val;
        dfs(root->right);
    }
};