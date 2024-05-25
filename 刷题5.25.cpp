//leetcode 2903. 找出满足差值条件的下标 I 两层循环

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> vec{-1,-1};
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(abs(i-j)>=indexDifference&&abs(nums[i]-nums[j])>=valueDifference)
                {
                    vec[0] = i;
                    vec[1] = j;

                    return vec;

                }
            }
        }
        return vec;
    }
};

//leetcode 121. 买卖股票的最佳时机 dp


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, price = 1e5;
        for(int i = 0;i < prices.size(); i++)
        {
            price = min(price,prices[i]);//每次循环结束记录最小单价
            profit = max(profit, prices[i]-price);//每次循环记录最大利润
        }
        return profit;
        
    }
};

//leetcode LCR 194. 二叉树的最近公共祖先 递归

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isTree(TreeNode* root, TreeNode* x)//该函数判断是否是跟所在的路径,如果当前路径就是,那么返回true,即递归回溯之后,首次调用的地方就是真
    {
        if(root == nullptr) return false;
        if(root == x) return true;
        return isTree(root->left, x) || isTree(root->right, x);
        }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == q || root == p) return root;
        //两个节点在左 还是在右
        //定义四个变量来存储对应的p,q两个节点的左右,用这样的方式更好完成下面的代码
        bool pInLeft = isTree(root->left, p);//p在根的左还是在右,如果在左,则p的左变量为真,右变量为假
        bool pInRight = !pInLeft;

        bool qInLeft = isTree(root->left, q);//q与p同理
        bool qInRight = !qInLeft;

        if((pInLeft && qInRight) || (pInRight && qInLeft)) //p在左,q在右;或者p在右,q在左,说明当前根就是要找的根,直接返回
            return root;
        if(pInLeft && qInLeft) //都在左,向左继续递归遍历找
            return lowestCommonAncestor(root->left, p, q);
        if(qInRight && pInRight)//或者都在右递归遍历找,因为题目说明肯定存在需要的节点,所以一定有值返回
            return lowestCommonAncestor(root->right, p, q);
        return nullptr;

    }
};