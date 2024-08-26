// leetcode 690. 员工的重要性 hash+dfs

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    unordered_map<int, Employee*> map;

public:
    int dfs(int id)
    {
        Employee* employee = map[id];
        int ans = employee->importance;
        for(auto &x : employee->subordinates)
        {
            ans += dfs(x);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto &e : employees)
        {
            map[e->id] = e;
        }
        return dfs(id);
    }
};

// leetcode 3146. 两个字符串的排列差 hash应用


class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> map;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            map[s[i]] = i;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += abs(map[t[i]]-i);
        }
        return ans;
    }
};