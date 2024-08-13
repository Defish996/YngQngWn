// leetcode 150. 逆波兰表达式求值


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        int n = tokens.size();
        for(int i = 0; i < n; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" )
            {
                int y = st.back();
                st.pop_back();
                int x = st.back();
                st.pop_back();
                int ans = 0;
                if(tokens[i] == "+")
                {
                    ans = x + y;
                }
                else if(tokens[i] == "-")
                {
                    ans = x - y;
                }
                else if(tokens[i] == "*")
                {
                    ans = x *y;
                }
                else
                {
                    ans = x / y;
                }
                st.push_back(ans);
            }
            else
            {
                st.push_back(stoi(tokens[i]));
            }
        }
        return st.back();
    }
};