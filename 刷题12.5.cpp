class Solution {
    vector<int> path;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int> nums, int n)// 传入的数组和层数
    {
        if(n == nums.size())// 层数为原数组的元素个数时， 进行递归出口的调用
        {
            ans.push_back(path);
            return;
        }
        // 不选这个元素
        dfs(nums, n + 1);

        // 选
        path.push_back(nums[n]);// 当前层数为第i层，所以选当前元素， 按理来说是要多一个参数，但是这个i与当前元素一样，所以可以不用再多一个参数
        dfs(nums, n + 1);
        path.pop_back();
    }
};


//
// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         vector<int> ans;
//         ans.push_back(nums[0]);
//         for(int i = 1; i < nums.size(); ++i)
//         {
//             ans.push_back(ans[i - 1] + nums[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i)
        {
            nums[i] = nums[i - 1] + nums[i];
        }   
        return nums;
    }
};
//前缀和

// hash sort 

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (const auto& e : s) {
            map[e]++;
        }
        vector<pair<char, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), [](pair<char, int> x, pair<char, int> y) {
            return x.second > y.second;
        });
        string ans;
        for (auto& e : vec) {
            while(e.second != 0) {
                ans += e.first;
                --e.second;
            }
        }
        return ans;
    }
};

// 方法二
// 首先进行计数添加到map
// 添加到map的同时得出最大的某个字符的长度
// 构建string类的vector桶， 这个vector的长度就是某个字符的最大长度
// 向对应个数的桶内添加他的char值
// 按照降序进行构造字符串
// 第一个for循环是从多到少的整体
// 第二个是对于某个string内的可能存在的ab， 或者是ba的单个遍历
// 第三个for循环是对针对某一个的对应个数的添加

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        int max_size = 0;
        for (auto& e : s) {
            max_size = max(max_size, ++map[e]);
        }
        vector<string> buckets(max_size + 1);// 为什么是string而不是char， 有可能a, b两个字符对应的个数都是3， 所以在buckets下标为3的数组中存放的是ab或者ba(按顺序存放)
        for (auto& [key, val] : map) {
            buckets[val].push_back(key);
        }
        string ans;
        for (int i = max_size; i > 0; --i) {
            const string& bucket = buckets[i];
            for (auto& e : bucket) {
                for (int j = 0; j < i; ++j) {
                    ans.push_back(e);
                }
            }
        }
        return ans;
    }
};
