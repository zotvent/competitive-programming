class Solution {
    
    double backtrack(unordered_map<string, unordered_map<string, double>>& g, string& cur, string& target, double product, unordered_set<string>& visited) {
        visited.insert(cur);
        double res = -1;
        
        if (g[cur].count(target) > 0) {
            res = product * g[cur][target];
        }
        else {
            string to;
            double weight;
            
            for (auto it = g[cur].begin(); it != g[cur].end(); it++) {
                to = it->first;
                weight = it->second;
                
                if (visited.count(to) > 0) {
                    continue;
                }
                else {
                    res = backtrack(g, to, target, product * weight, visited);
                    
                    if (res != -1) {
                        break;
                    }
                }
            }
        }
        
        visited.erase(cur);
        return res;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res(queries.size(), -1);
        unordered_map<string, unordered_map<string, double>> g;
        unordered_set<string> visited;
        string from, to;
        
        for (int i = 0; i < equations.size(); i++) {
            from = equations[i][0];
            to = equations[i][1];
            g[from][to] = values[i];
            g[to][from] = 1.0 / values[i];
        }
        
        for (int i = 0; i < queries.size(); i++) {
            from = queries[i][0];
            to = queries[i][1];
            
            if (g.count(from) == 0 || g.count(to) == 0) {
                res[i] = -1;
            }
            else if (from == to) {
                res[i] = 1;
            }
            else {
                res[i] = backtrack(g, from, to, 1, visited);
            }
        }
        
        return res;
    }
};