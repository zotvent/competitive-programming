class Solution {
    
    double backtrack(unordered_map<string, unordered_map<string, double>>& g, string cur, string dest, unordered_set<string>& used, double product) {
        if (cur == dest) {
            return product;
        }
        
        used.insert(cur);
        double next;
        
        for (auto it = g[cur].begin(); it != g[cur].end(); it++) {
            if (used.count(it->first) == 0) {
                next = backtrack(g, it->first, dest, used, product * it->second);
                if (next != -1.0) {
                    used.erase(cur);
                    return next;
                }
            }
        }
        
        used.erase(cur);
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> g;
        unordered_set<string> used;
        
        for (int i = 0; i < equations.size(); i++) {
            g[equations[i][0]][equations[i][1]] = values[i];
            g[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        
        for (auto& q: queries) {
            if (g.count(q[0]) == 0 || g.count(q[1]) == 0) {
                res.push_back(-1);
            }
            else {
                res.push_back(backtrack(g, q[0], q[1], used, 1));
            }
        }
        
        return res;
    }
};