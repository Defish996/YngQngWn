//leetcode 逆波兰表达式 function +stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        map<string, function<int(int, int)>> map = 
        {
            {"+", [](int x, int y){return x + y;}},
            {"-", [](int x, int y){return x - y;}},
            {"*", [](int x, int y){return x * y;}},
            {"/", [](int x, int y){return x / y;}}
        };
        for(auto &x : tokens)
        {
            if(map.count(x))
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(map[x](left,right));
            }
            else
            {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};

c++11语法验证
//#include <iostream>
//using namespace std;
//int main()
//{
//
//
//
//
//
//	return 0;
//
// 
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>> result;
    if (root == nullptr) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> v;
        while (levelSize--) {
            TreeNode* front = q.front();
            q.pop();

            v.push_back(front->val);

            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }

        result.push_back(v);
    }

    return result;
}
//
//int main() 
//{
//    // 创建一棵简单的二叉树：
//    //       3
//    //     /   \
//    //    9     20
//    //         /  \
//    //        15   7
//    TreeNode* root = new TreeNode(3);
//    root->left = new TreeNode(9);
//    root->right = new TreeNode(20);
//    root->right->left = new TreeNode(15);
//    root->right->right = new TreeNode(7);
//
//    vector<vector<int>> levels = levelOrder(root);
//
//    // 输出结果
//    for (const auto& level : levels) {
//       cout << "Level: ";
//        for (const auto& nodeValue : level) {
//            cout << nodeValue << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

//class A
//{
//public:
//    void func_A()
//    {}
//    static void func_B()
//    {}
//};
//int main()
//{
//    function<void()> f2 = A::func_B;
//
//    
//    
//    A a;
//    function<void()> f1 = bind(&A::func_A, &a);
//    cout << typeid(f1).name() << endl;
//    //auto f2 = bind(&A::func_A, &a);
//    cout << typeid(f2).name() << endl;
//    return 0;
//}

void  func(int a, int b, int c)
{
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
int main() {

    function<void(int, int)> f = bind(func, placeholders::_1, 10, placeholders::_2);
    f(1, 3);
    return 0;
}