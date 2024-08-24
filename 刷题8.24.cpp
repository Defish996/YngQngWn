// leetcode 61.加一

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        for(int i = n -1; i >= 0; i--)
        {
            digits[i] += 1;
            if(digits[i] <= 9)
            {    
                return digits;
            }
            else
            {
                digits[i] = 0;
                carry = 1;
            }
        }
  
        vector<int> vec(n + 1);
        vec[0] = 1;
        return vec;
    }
};