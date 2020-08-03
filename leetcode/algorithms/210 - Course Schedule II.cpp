class Solution {

    bool dfs(int v, vector<vector<int>>& g, vector<int>& color, vector<int>& res) {
        bool ans = true;
        color[v] = 2;
      
        int to;
        for (int i = 0; i < g[v].size(); i++) {
            to = g[v][i];
            
            if (color[to] == 2) {
                return false;
            }
            else if (color[to] == 0) {
                ans &= dfs(to, g, color, res);
            }
        }
        
        color[v] = 1;
        res.push_back(v);
        
        return ans;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;

        vector<vector<int>> g(numCourses);
        vector<int> color(numCourses, 0);
        
        for (auto& i: prerequisites) {
            g[i[0]].push_back(i[1]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0) {
                if (!dfs(i, g, color, res)) {
                    res.clear();
                    break;
                }
            }
        }
        
        return res;
    }
};