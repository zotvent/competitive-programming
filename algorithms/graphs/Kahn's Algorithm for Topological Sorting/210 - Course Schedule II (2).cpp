// https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> g(numCourses);
        vector<int> visited(numCourses, 0), degree(numCourses, 0);
        queue<int> q;
        
        for (auto& i: prerequisites) {
            g[i[1]].push_back(i[0]);
            degree[i[0]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            res.push_back(v);
            
            for (auto& to: g[v]) {
                degree[to]--;
                
                if (!visited[to] && degree[to] == 0) {
                    q.push(to);
                    visited[to] = 1;
                }
            }
        }
        
        for (auto& i: visited) {
            if (i == 0) res.clear();
        }
        
        return res;
    }
};