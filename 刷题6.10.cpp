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

//380. O(n) 时间插入、删除和获取随机元素
class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(find(num.begin(), num.end(), val) != num.end())//找到啦,存在
        {
            return false;
        }
        else
        {
            num.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        auto e = find(num.begin(), num.end(), val);
        if(e != num.end())
        {
            num.erase(e);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int tmp = rand() % (int)num.size();
        return num[tmp];

    }
private:
    vector<int> num; 
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

