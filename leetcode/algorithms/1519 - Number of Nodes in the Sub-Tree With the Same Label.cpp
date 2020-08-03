class Solution {
    
    vector<int> dfs(int v, vector<vector<int>>& g, string& labels, vector<int>& res, vector<int>& used) {
        vector<int> m(26, 0);
        
        used[v] = 1;
        int to;
        vector<int> next;
        
        for (int i = 0; i < g[v].size(); i++) {
            to = g[v][i];
            
            if (!used[to]) {
                next = dfs(to, g, labels, res, used);
            
                for (int j = 0; j < m.size(); j++) {
                    m[j] += next[j];
                }
            }
        }
        
        m[labels[v] - 'a']++;
        res[v] = m[labels[v] - 'a'];
        
        return m;
    }
    
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n, 1);
        
        vector<vector<int>> g(n);
        vector<int> used(n, 0);
        
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        dfs(0, g, labels, res, used);
        
        return res;
    }
};