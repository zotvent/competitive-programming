class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> g;
        g.resize(nodes);
        
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] >= 0) {
                g[parent[i]].push_back(i);
            }
        }
        
        int res = nodes;
        pair<int, int> tmp = dfs(g, value, 0, res);
        return (tmp.first == 0 ? 0 : res);
    }
    
    pair<int, int> dfs(vector<vector<int>>& g, vector<int>& value, int cur, int& cnt) {
        int sum = value[cur];
        int nodes = 1;
        
        pair<int, int> child;
        
        for (int i = 0; i < g[cur].size(); i++) {
            int to = g[cur][i];
            child = dfs(g, value, to, cnt);
            
            if (child.first == 0) cnt = cnt - child.second;
            else {
                sum += child.first;
                nodes += child.second;
            }
        }
        
        return {sum, nodes};
    }
};