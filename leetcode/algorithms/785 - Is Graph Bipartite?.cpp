class Solution {
    
    void dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& colors, int color, int node, bool& res) {
        visited[node] = 1;
        colors[node] = color;
        
        for (int i = 0; i < graph[node].size(); i++) {
            int to = graph[node][i];
            int newColor = (color + 1) % 2;
            
            if (!visited[to]) {
                dfs(graph, visited, colors, newColor, to, res);
            }
            else if (colors[to] != newColor) {
                res = false;
                return;
            }
        }
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool res = true;
        const int n = graph.size();
        vector<int> visited(n, 0), colors(n, 0);
        
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                dfs(graph, visited, colors, 0, node, res);
            }
        }
        
        return res;
    }
};