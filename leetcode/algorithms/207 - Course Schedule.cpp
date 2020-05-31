class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> color(numCourses, 0);
        
        for (auto& i: prerequisites) {
            g[i[0]].push_back(i[1]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0) {
                dfs(g, color, i);
            }
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (color[i] != 2) {
                return false;
            }
        }
        
        return true;
    }
    
    void dfs(vector<vector<int>>& g, vector<int>& color, int v) {
        color[v] = 1;
        
        int to;
        
        for (int i = 0; i < g[v].size(); i++) {
            to = g[v][i];
            
            if (color[to] == 0) {
                dfs(g, color, to);
            }
            else if (color[to] == 1) {
                return;
            }
        }
        
        color[v] = 2;
    }
};