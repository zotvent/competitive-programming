/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> m;
        for (auto e: employees)
            m[e->id] = e;
        return dfs(m, id);
    }
    
    int dfs(map<int, Employee*> &m, int id) {
        int total = m[id]->importance;
        for (int i = 0; i < m[id]->subordinates.size(); i++)
            total += dfs(m, m[id]->subordinates[i]);
        return total;
    }
};