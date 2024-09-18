// 移动0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                continue;
            }
            swap(nums[left], nums[i]);
            ++left;
        }
    }
};


// 复写0
class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int cur = 0, dest = -1;
        for(;; cur++)
        {
            if(arr[cur] != 0)
            {
                dest++;
                if(dest == arr.size() - 1)
                {
                    break;
                }
            }
            else
            {
                dest += 2;
                if(dest == arr.size() - 1 || dest == arr.size())
                {
                    break;
                }
            }
        }
        if(dest == arr.size())
            {
                arr[--dest] = 0;
                dest--;
                cur--;
            }
        while(dest != cur)
        {
            
            if(arr[cur] == 0)
                {
                    arr[dest--] = 0;
                    arr[dest--] = 0;
                    cur--;
                }     
            else
                {
                    arr[dest--] = arr[cur--];
                }    
        }
    }
};