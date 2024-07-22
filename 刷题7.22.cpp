//删除字符串中的所有相邻重复项


class Solution {
public:
    string removeDuplicates(string S) {
        string stk;
        for (char ch : S) {
            //栈不为空, 栈顶元素为当前遍历的元素,则删除栈内元素
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            } else {
                //否则元素入栈
                stk.push_back(ch);
            }
        }
        return stk;
    }
};