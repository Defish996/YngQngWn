//leetcode 98. 验证二叉搜索树 单纯逻辑判断+递归+回溯判断

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
    long pre = LONG_MIN; // 因为数据最小是-2^31 小于INT_MIN, 所以使用LONG_MIN,有的平台下long和int相当, 可以使用long long
    //创建该全局变量可以保存当前值, 与下次中序遍历的值进行比较
    //二叉树搜索树的中序遍历是一个有序数列
public:
    bool isValidBST(TreeNode* root) {
        // 递归出口
        if(root == nullptr) return true;
        // 中序遍历, 先判左节点
        bool left = isValidBST(root->left);
        // 中序遍历, 中间节点判断
        bool cur = false;
        if(root->val > pre) // 我们给予这个pre的值就是当前节点的前一个节点的值, 虽然从代码到这边没有说明, 但是确信事实就是如此
            cur = true;     // 或者是认为这是某次中间的遍历, pre就已经携带了前一个节点的val
        pre = root->val; // 当前中序遍历对中间节点的遍历已经经过, 所以更新pre值, 确保与下次的节点值进行比较
        // 中序遍历, 右节点判断
        bool right = isValidBST(root->right);
        // 函数体, 实际的逻辑意义
        return left && right && cur;// 只有当前节点, 左树, 右树, 都为二叉搜索树时, 才是二叉搜索树
    }
};

// 修正版, 对他进行裁剪, 只有当左树, 或者是root->val < left->val, 即不满足, 进行裁剪, 优化时间
class Solution {
    long pre = LONG_MIN; 
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        bool left = isValidBST(root->left);
        // 剪枝
        if(left == false) return false; 
        bool cur = false;
        if(root->val > pre) 
            cur = true;    
        // 剪枝
        if(cur == false) return false;
        pre = root->val; 
        bool right = isValidBST(root->right);
        
        return left && right && cur;
    }
};
