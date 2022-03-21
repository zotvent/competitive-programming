class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        int res = 0;
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        
        for (auto& r: relations) {
            int from = r[0] - 1;
            int to = r[1] - 1;
            g[from].push_back(to);
            indegree[to]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            res++;
            
            for (; size > 0; size--) {
                int v = q.front();
                q.pop();
                
                for (auto& to: g[v]) {
                    indegree[to]--;
                    if (indegree[to] == 0) {
                        q.push(to);
                    }
                }
            }
        }
        
        for (auto& i: indegree) {
            if (i != 0) res = -1;
        }
        
        return res;
    }
};