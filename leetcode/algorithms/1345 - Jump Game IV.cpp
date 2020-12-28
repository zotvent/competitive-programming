class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int n = arr.size();
        
        if (n == 1) {
            return 0;
        }
        
        unordered_map<int, vector<int>> g;
        
        for (int i = 0; i < n; i++) {
            g[arr[i]].push_back(i);
        }
        
        int res = 0;
        vector<int> cur(1, 0), next;
        unordered_set<int> used;
        
        while (!cur.empty()) {
            for (auto& node: cur) {
                if (node == n - 1) {
                    return res;
                }
                
                for (auto& child: g[arr[node]]) {
                    if (used.count(child) == 0) {
                        used.insert(child);
                        next.push_back(child);
                    }
                }
                
                g[arr[node]].clear();
                
                if (node + 1 < n && used.count(node + 1) == 0) {
                    used.insert(node + 1);
                    next.push_back(node + 1);
                }
                
                if (node - 1 >= 0 && used.count(node - 1) == 0) {
                    used.insert(node - 1);
                    next.push_back(node - 1);
                }
            }
            
            cur = next;
            next.clear();
            res++;
        }
        
        return -1;
    }
};