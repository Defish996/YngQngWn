// leetcode 242. 有效的字母异位词 hash应用


class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26];
        for(auto &e : s)
        {
            hash[e - 'a']++;
        }
        for(auto &e : t)
        {
            hash[e - 'a']--;
        }
        for(auto &x : hash)
        {
            if(x != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// 二叉树中的节点个数 

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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;// 1为当前节点
    }
};

// leetcode 258. 各位相加
// 模拟法
class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
    all:
        while(num > 0)
        {
            ans += num % 10;
            num /= 10;
        }
        if(ans > 9)
        {
            num = ans;
            ans = 0;
            goto all; 
        }
        return ans;
    }
};
// 数学规律 同余定理的应用
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};


 