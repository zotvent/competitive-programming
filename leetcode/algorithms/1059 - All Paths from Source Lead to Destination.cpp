class Solution {
    
    bool dfs(vector<vector<int>>& g, vector<int>& colors, int v, int destination) {
        if (colors[v] == 1) return false;
        if (g[v].empty()) return v == destination;
        
        colors[v] = 1;
        for (auto& next: g[v]) {
            if (!dfs(g, colors, next, destination)) {
                return false;
            }
        }
        colors[v] = 0;
        
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        vector<int> colors(n, 0);
        
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
        }
        
        return dfs(g, colors, source, destination);
    }
};