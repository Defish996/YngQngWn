// 904. 水果成篮 阅读理解+滑动窗口+hash


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        int hash[100001] = { 0 };
        int kind = 0;// 记录水果的种类
        int ans = 0;
        while(right < n)
        {
            if(hash[fruits[right]] == 0) ++kind;// 首次进入肯定是新品种, 所以种类数++
            hash[fruits[right]]++;
            // if(hash.size() > 2)
            // {
            //     hash[fruits[left]]--;
            // }
            // ans = max(ans, right - left + 1);
            // 为什么if不行, 同样传入的值在进行出窗口的时候, 虽然在hash中size只是种类统计, 但是不知道每个种类的具体分部, 所以还是一一减去较好, 所以还是使用while
            while(kind > 2)
            {
                hash[fruits[left]]--;
                if(hash[fruits[left]] == 0) --kind;
                left++;
                // 同时减去这个值使它变为0之后, 还要把它
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;

    }
};