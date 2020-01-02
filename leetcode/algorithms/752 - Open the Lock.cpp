class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int moves = 0;
        
        unordered_set<string> used;
        queue<string> q;
        q.push("0000");
        
        for (int i = 0; i < deadends.size(); i++) {
            used.insert(deadends[i]);
        }
        
        string v, to;
        int sz;
        char c;
        
        while (!q.empty()) {
            sz = q.size();
            
            for (int o = 0; o < sz; o++) {
                v = q.front();
                q.pop();
                
                if (used.count(v) > 0) continue;
                if (v == target) return moves;
                
                for (int i = 0; i < 4; i++) {
                    for (int j = -1; j <= 1; j += 2) {
                        c = next(v[i], j);
                        
                        to = v;
                        to[i] = c;
                        
                        if (used.count(to) == 0) {
                            q.push(to);
                        }
                    }
                }
                
                used.insert(v);
            }
            
            moves++;
        }
        
        return -1;
    }
    
    char next(char c, int dif) {
        c += dif;
        if (c > '9') c = '0';
        if (c < '0') c = '9';
        return c;
    }
};