class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n);
        
        for (auto& e: edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (; size > 0; size--) {
                int cur = q.front();
                q.pop();
                
                for (auto& next: g[cur]) {
                    if (visited[next]) {
                        return false;
                    }
                    g[next].erase(cur);
                    visited[next] = 1;
                    q.push(next);
                }
                
                g[cur].clear();
            }
        }
        
        for (auto& i: visited) {
            if (!i) return false;
        }
        
        return true;
    }
};