class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        
        vector<unordered_set<int>> g(n);
        
        for (auto& e: edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        
        vector<int> leaves, newLeaves;
        
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        
        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            
            for (auto& leaf: leaves) {
                for (auto& to: g[leaf]) {
                    g[to].erase(leaf);
                    
                    if (g[to].size() == 1) {
                        newLeaves.push_back(to);
                    }
                }
            }
            
            leaves = newLeaves;
            newLeaves.clear();
        }
        
        return leaves;
    }
};