//575. 分糖果 hash+模拟

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> map;
        for(auto& e : candyType)
        {
            map[e]++;
        }
        vector<pair<int, int>> vec(map.begin(), map.end());
        int n = vec.size();
        int num = candyType.size() / 2;
        return num < n ? num : n;
    }
};

//2928. 给小朋友们分糖果 I 模拟题,昨天没理解,今天稳住心态,终于算是会了

class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for(int i = 0; i <= limit; i++)//第一个小盆友分到的糖果
        {
            for(int j = 0; j <= limit; j++)//第二个小盆友分到的糖果
            {
                if(i + j > n) break;//若前两个小盆友把糖果分完就是不合理,跳出循环
                if(n-i-j <= limit)//第三个小盆友分到的糖果
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};