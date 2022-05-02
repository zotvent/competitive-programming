class Solution {
    
    bool dfs(int v, vector<vector<int>>& graph, vector<int>& colors, int color) {
        colors[v] = color;
        
        for (auto& to: graph[v]) {
            if (colors[to] == -1) {
                bool next = dfs(to, graph, colors, (color + 1) % 2);
                if (!next) return false;
            }
            else if (colors[to] == color) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> colors(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!dfs(i, graph, colors, 0)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};