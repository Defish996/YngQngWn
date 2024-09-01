// 290. 单词规律 hash双向映射

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        int i = 0;
        int j = 0;
        while(i < pattern.size())
        {
            char c = pattern[i];
            string word;
            while(s[j] != ' ' && j < s.size())
            {
                word += s[j++];
            }
            if(map1.find(c) != map1.end() && map1[c] != word || map2.find(word) != map2.end() && map2[word] != c)
            {
                return false;
            }
            map1[c] = word;
            map2[word] = c;
            j++;
            i++;
        }
        cout << j << "size: " << s.size();
        if(j != s.size() + 1) return false;
        return true;
    }
};

// 全排列
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[7];
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ret;
    }
    void dfs(vector<int> &nums)
    {
        if(nums.size() == path.size())
        {
            ret.push_back(path);
            return; 
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(check[i] == true) continue;
            check[i] = true;
            path.push_back(nums[i]);
            dfs(nums);
            path.pop_back();// 恢复现场
            check[i] = false;
        }
    } 
};

// 1450. 在既定时间做作业的学生人数 计数


class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ret = 0;
        for(int i = 0; i < startTime.size(); i++)
        {
            if(endTime[i] >= queryTime && startTime[i] <= queryTime)
            {
                ret++;
            }
        }
        return ret;
    }
};