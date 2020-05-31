class Solution {
private:
    vector<vector<int>> g;
    unordered_map<int, int> color;
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        g.resize(N + 1);
        
        for (auto& i: dislikes) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        
        for (int i = 1; i <= N; i++) {
            if (color.count(i) == 0 && !dfs(i, 0)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs(int v, int c) {
        if (color.count(v) > 0) {
            return color[v] == c;
        }
        
        color[v] = c;
        
        for (int i = 0; i < g[v].size(); i++) {
            if (!dfs(g[v][i], (c + 1) % 2)) {
                return false;
            }
        }
        
        return true;
    }
};