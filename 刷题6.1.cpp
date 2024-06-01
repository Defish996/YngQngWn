//412. Fizz Buzz ,模拟题 //[0,n).n   [1,n] n-1


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i = 1; i <= n; i++)//[0,n).n   [1,n] n-1
        {
            if(i % 3 == 0 && i % 5 != 0)
            {
                ans[i-1] = "Fizz";
            }
            else if(i % 5 == 0 && i % 3 != 0)
            {
                ans[i-1] = "Buzz";
            }
            else if(i % 3 == 0 && i % 5 == 0)
            {
                ans[i-1] = "FizzBuzz";
            } 
            else
            {
                ans[i-1] = to_string(i);
            }
        }
        return ans;
    }
};