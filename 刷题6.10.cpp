//881. 救生艇 排序+双指针+贪心


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0, right = people.size() - 1;
        int ans = 0;
        sort(people.begin(), people.end());
        while(left <= right)
        {
            if(people[left] + people[right] > limit) 
            {
                right--;
            }
            else if(people[left] + people[right] <= limit)
            {
                left++;
                right--;
            }
            else{
                break;
            }
            ans++;
        }
        return ans;
    }
};