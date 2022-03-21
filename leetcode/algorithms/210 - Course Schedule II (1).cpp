class Solution {
    
    bool dfs(int v, vector<vector<int>>& g, vector<int>& colors, vector<int>& res) {
        colors[v] = 1;
        bool valid = true;
        
        for (auto& to: g[v]) {
            if (colors[to] == 0) {
                valid &= dfs(to, g, colors, res);
                if (!valid) return false;
            }
            else if (colors[to] == 1) {
                return false;
            }
        }
        
        colors[v] = 2;        
        res.push_back(v);
        
        return valid;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res, colors(numCourses, 0);
        vector<vector<int>> g(numCourses);
        
        for (auto& i: prerequisites) {
            g[i[1]].push_back(i[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (colors[i] != 0) continue;
            if (!dfs(i, g, colors, res)) {
                res.clear();
                break;
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};