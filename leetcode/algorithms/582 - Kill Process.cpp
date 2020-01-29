class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        
        map<int, vector<int>> g;
        
        for (int i = 0; i < pid.size(); i++) {
            if (ppid[i] == 0) continue;
            g[ppid[i]].push_back(pid[i]);
        }
        
        queue<int> q;
        q.push(kill);
        int v, sz;
        
        while (!q.empty()) {
            sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                v = q.front();
                q.pop();
                
                res.push_back(v);
                
                for (int j = 0; j < g[v].size(); j++) {
                    q.push(g[v][j]);
                }
            }
        }
        
        return res;
    }
};