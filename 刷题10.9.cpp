// 728. 自除数, 模拟题, 两篇blog 明天优化

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        int flag = 0;
        for(;left <= right; ++left)
        {
            int num = left;
            while(num && flag == 0)
            {
                int tmp = num % 10;
                if(tmp == 0) 
                {
                    flag = 0;
                    goto end;
                }
                cout << tmp << endl;
                if(left % tmp != 0)
                {
                    flag = 1;
                    break;
                } 
                num /= 10;
            }
            if(flag == 0)
            {
                ans.push_back(left);
            }
            flag = 0;
        end:
        }
    return ans;
    }
};