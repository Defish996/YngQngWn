//100. 相同的树 递归

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)//当两个当前节点都是nullptr时,为相同的树
        {
            return true;
        }
        else if(p==nullptr || q==nullptr)//第一个if已经判断,两个都为真停止,那么后续有一个为nullptr即为不是相同的树
        {
            return false;
        }
        else if(p->val != q->val)//为nullptr判断结束,写一步判断值是否相等
        {
            return false;
        }
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);//下一步递归进行判断
    }
};