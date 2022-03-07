class Solution {
    
    void dfs(int v, vector<vector<int>>& g, vector<int>& seen) {
        seen[v] = 1;
        for (auto& to: g[v]) {
            if (!seen[to]) {
                dfs(to, g, seen);
            }
        }
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        vector<int> seen(n, 0);
        
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(source, g, seen);
        
        return seen[destination];
    }
};