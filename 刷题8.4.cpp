//leetcode 50. Pow(x, n) 快速幂递归法


class Solution {
public:
    double myPow(double x, int n) {
        return n < 0 ? 1.0 / pow(x, -(long long)n) : pow(x, n);
        //1.因为int最大为2^31 - 1
        //  但是数据范围包括-2^31, 也就是2^31, 所以要强转为long long
        //  正数不用, 因为是2^31-1
        //2.负数还要在返回的结果上进行取倒数
    }
    double pow(double x, long long n) {
        if(n == 0) return 1.0;//递归出口
        double tmp = pow(x, n / 2);//函数头
        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;//保存当前的pow函数结果后, 实际的函数体的作用
        //当n为奇数时, 要执行tmp * tmp * x
    }
    
};

// leetcode 2331. 计算布尔二叉树的值 递归法

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
    bool evaluateTree(TreeNode* root) {
        // 函数出口, 更严谨是这样, 但是本身1就是true, 所以可以直接省略 == 1 ? true : false, 这一步
        //if(root->left == nullptr) return root->val == 1 ? true : false;
        // 为空只需判断一边即可, 因为题目中说明给出的都是完整二叉树,完整二叉树 是每个节点有 0 个或者 2 个孩子的二叉树
        if(root->left == nullptr) return root->val;
        // 对当前root的左右节点进行判断,这是函数头
        bool left = evaluateTree(root -> left);
        bool right = evaluateTree(root -> right);
        // 进行实际函数体的运算
        return root -> val == 2 ? left | right : left & right;
    }
};