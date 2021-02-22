class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        const int n = pid.size();
        unordered_map<int, vector<int>> g(n);
        
        for (int i = 0; i < n; i++) {
            g[ppid[i]].push_back(pid[i]);
        }
        
        queue<int> q;
        int cur, to;
        
        q.push(kill);
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            res.push_back(cur);
            
            for (int i = 0; i < g[cur].size(); i++) {
                to = g[cur][i];
                q.push(to);
            }
        }
        
        return res;
    }
};