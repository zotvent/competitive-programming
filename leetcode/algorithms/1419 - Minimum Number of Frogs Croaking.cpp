class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int res = -1;
        
        vector<vector<int>> g(5);
        int index;
        
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            if (croakOfFrogs[i] == 'c') index = 0;
            else if (croakOfFrogs[i] == 'r') index = 1;
            else if (croakOfFrogs[i] == 'o') index = 2;
            else if (croakOfFrogs[i] == 'a') index = 3;
            else index = 4;
            
            g[index].push_back(i);
        }
        
        int mn = (int) g[0].size();
        int mx = (int) g[0].size();
        
        for (auto i: g) {
            mn = min(mn, (int) i.size());
            mx = max(mx, (int) i.size());
        }
        
        if (mn == mx && valid(g)) {
            res = 1;
            
            queue<int> q;
            
            for (int i = 0; i < g[0].size(); i++) {
                while (!q.empty() && q.front() < g[0][i]) {
                    q.pop();
                }
                q.push(g[4][i]);
                
                res = max(res, (int) q.size());
            }
        }
        
        return res;
    }
    
    bool valid(vector<vector<int>>& g) {
        bool condition;
        
        for (int i = 0; i < g[0].size(); i++) {
            condition = g[0][i] < g[1][i] && g[1][i] < g[2][i] && g[2][i] < g[3][i] && g[3][i] < g[4][i];
            
            if (!condition) return false;
        }
        return true;
    }
};