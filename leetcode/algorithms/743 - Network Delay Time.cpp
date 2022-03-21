class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> g(n + 1);
        const int inf = 1e9;
        vector<int> dp(n + 1, inf);
        priority_queue<int, vector<int>, greater<int>> q;
        
        for (auto& t: times) {
            g[t[0]].push_back({t[1], t[2]});
        }
        
        dp[k] = 0;
        q.push(k);
        
        while (!q.empty()) {
            int v = q.top();
            q.pop();
            
            for (auto& i: g[v]) {
                int to = i[0];
                int weight = i[1];
                
                if (dp[to] > dp[v] + weight) {
                    dp[to] = dp[v] + weight;
                    q.push(to);
                }
            }
        }
        
        int res = 0;
        
        for (int i = 1; i <= n; i++) {
            if (dp[i] == inf) {
                res = -1;
                break;
            }
            res = max(res, dp[i]);
        }
        
        return res;
    }
};