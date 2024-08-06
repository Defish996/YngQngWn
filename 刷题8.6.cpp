//814. 二叉树剪枝 决策树使用


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
    // TreeNode* pruneTree(TreeNode* root) {
    //     if(root == nullptr) return nullptr;
    //     if(root->val == 0)
    //     {
    //         if(pruneTree(root->left) == nullptr && pruneTree(root->right) == nullptr) //即使子树被修剪了，root->left 和 root->right 仍然指向原来的子树节, 未进行修改, 应该将修改的结果返回给上层的函数
    //         {
    //             root = nullptr;
    //         }
        
    //     }
    //     return root;
    // }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr) return nullptr; // 递归出口
        
        root->left = pruneTree(root->left);// 函数头
        root->right = pruneTree(root->right);

        if(root->left == nullptr && root->right == nullptr && root->val == 0) // 函数体
        {
            root = nullptr;
        }
        return root;
    }
};