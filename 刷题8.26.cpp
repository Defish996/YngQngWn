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