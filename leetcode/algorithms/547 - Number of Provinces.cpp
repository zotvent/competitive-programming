class Solution {
    
    void bfs(vector<vector<int>>& g, vector<int>& used, int start) {
        queue<int> q;
        int from;
        
        q.push(start);
        used[start] = 1;
        
        while (!q.empty()) {
            from = q.front();
            q.pop();
            
            for (int to = 0; to < g[from].size(); to++) {
                if (g[from][to] && !used[to]) {
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        const int n = isConnected.size();
        vector<int> used(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                bfs(isConnected, used, i);
                res++;
            }
        }
        
        return res;
    }
};