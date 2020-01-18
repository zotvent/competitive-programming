class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        
        int groups = 0;
        
        vector<vector<int>> g;
        g.resize(n);
        vector<int> used(n, 0);
                
        for (int i = 0; i < connections.size(); i++) {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(g, used, i);
                groups++;
            }
        }
        
        return groups - 1;
    }
    
    void dfs(vector<vector<int>>& g, vector<int>& used, int v) {
        used[v] = 1;
        
        int to;
        for (int i = 0; i < g[v].size(); i++) {
            to = g[v][i];
            
            if (!used[to]) {
                dfs(g, used, to);
            }
        }
    }
};