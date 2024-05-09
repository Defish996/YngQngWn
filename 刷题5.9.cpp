class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int left = 0,right = plants.size()-1,ans = 0,tmp_caA = capacityA,tmp_caB =capacityB;
        while(left<right)
        {
            if(plants[left]<=tmp_caA)
            {
                tmp_caA-=plants[left++];
            }
            else
            {
                ++ans;
                tmp_caA = capacityA - plants[left++];
            }
            if(plants[right]<=tmp_caB)
            {
                tmp_caB-=plants[right--];
            }
            else
            {
                ++ans;
                tmp_caB = capacityB - plants[right--];
            }
        }
        if(left==right)
        {
            if(max(tmp_caA,tmp_caB)<plants[left]) ans++;
        }
        return ans;
    }
};