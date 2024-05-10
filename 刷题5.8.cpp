//leetcode965. 单值二叉树
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr)
            return true;
        if(root->left&&root->left->val!=root->val) return false;
        if(root->right&&root->right->val!=root->val) return false; 

        return isUnivalTree(root->left)&&isUnivalTree(root->right);
    }
};

//leetcode2079. 给植物浇水 O(N)100%
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int i = capacity;
        int ans = 0;
        int step = 0;
        for(const auto& e : plants)
        {
            if(i >= e)
            {
                ++step;
                ++ans;
                i-=e;
            }
            else
            {
                ans += step;
                i=capacity;
                ans += ++step;
                i-=e;
            }
        } 
        return ans;
    }
};

//leetcode606. 根据二叉树创建字符串
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
