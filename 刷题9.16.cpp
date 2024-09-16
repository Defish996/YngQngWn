// 2011. 执行操作后的变量值

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto &op : operations)
        {
            for(auto &e : op)
            {
                if(e == '+')
                {
                    ++ans;
                    break;
                }
                else if(e == '-')
                {
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};