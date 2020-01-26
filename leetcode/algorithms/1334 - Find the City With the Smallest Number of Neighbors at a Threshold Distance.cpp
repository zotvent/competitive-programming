class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int inf = (int) (1e9);
        vector<vector<int>> g(n, vector<int>(n, inf));
        
        for (auto e: edges) {
            g[e[0]][e[1]] = e[2];
            g[e[1]][e[0]] = e[2];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    
                    if (g[i][k] < inf && g[k][j] < inf) {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
        
        int cnt, res = -1, mn = inf;
        
        for (int i = n - 1; i >= 0; i--) {
            cnt = 0;
            
            for (int j = 0; j < n; j++) {
                if (g[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            
            if (cnt < mn) {
                mn = cnt;
                res = i;
            }
        }
        
        return res;
    }
};