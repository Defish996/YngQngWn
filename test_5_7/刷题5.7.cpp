leetcode606,根据二叉树创建字符串


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
    string tree2str(TreeNode* root) {
        string st;
        if(root==nullptr)
        {
            return st;
        }
        st += to_string(root->val);
        if(root->left || root->right)
        {
            st+="(";
            st += tree2str(root->left);
            st+=")";           
        }

        if(root->right==nullptr)
            return st;
        st+="(";
        st += tree2str(root->right);
        st+=")";
        return st;

    }
};