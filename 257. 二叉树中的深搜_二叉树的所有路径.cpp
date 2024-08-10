//leetcode 257. 二叉树中的深搜_二叉树的所有路径


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
    vector<string> ret;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        if(root == nullptr) return ret;
        dfs(root, path);
        return ret;
    }
    void dfs(TreeNode *root, string path)
    {
        path +=to_string(root->val);
        if(root ->left == nullptr && root->right == nullptr)
        {

            ret.push_back(path);
            return;
        }
        path += "->";
        if(root->left) dfs(root->left, path);
        if(root->right) dfs(root->right, path);
    }
};