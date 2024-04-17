//ֻ����һ�ε�����1 2 3
//1.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& a : nums)
        {
            ans ^= a;
        }
        return ans;
    }
};


//2.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto& e : nums)
        {
            ++um[e];
        }
        for (auto& [num, occ] : um)
        {
            if (occ == 1)
            {
                return num;
                break;
            }
        }
        return -1;
    }
};

//3.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;//��ֵ��(ֵ,����)(���������ʼ��Ϊ0)
        //�����nums���б���,��ֵ���hash��
        for (auto& e : nums)
        {
            ++um[e];//������ֵ֮ǰδ�����Զ���ӽ�hash;�����ֶԴ���+1
        }
        vector<int> vec;
        for (auto& [e, occ] : um)//�����hash���б���,�����Զ�,����������
        {
            if (occ == 1)
            {
                vec.push_back(e);
            }
        }
        return vec;
    }
};

//���������������
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (!st.empty() || cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();

            ans.push_back(cur->val);

            cur = cur->right;
        }
        return ans;
    }
};


//��ŵ������(�ݹ�)

class Solution {
public:
    void hanota(vector<int>& a, vector<int>& b, vector<int>& c) {
        dfs(a, b, c, a.size());
    }
    void dfs(vector<int>& a, vector<int>& b, vector<int>& c, int n)//nΪҪ��������
    {
        if (n == 1)
        {
            c.push_back(a.back());
            a.pop_back();
            // c.push_back(a[0]);
            // a.pop_back();
            return;
        }
        dfs(a, c, b, n - 1);
        c.push_back(a.back());
        a.pop_back();
        dfs(b, a, c, n - 1);
    }
};

//