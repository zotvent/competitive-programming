class Solution {
    
    struct UnionFind {
        
        UnionFind(int n) {
            ranks.assign(n + 1, 0);
            groups.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                groups[i] = i;
            }
        }
        
        bool connect(int l, int r) {
            int left = find(l), right = find(r);
            
            if (left == right) {
                return false;
            }
            
            if (ranks[left] > ranks[right]) {
                groups[right] = left;
            }
            else if (ranks[right] > ranks[left]) {
                groups[left] = right;
            }
            else {
                groups[left] = right;
                ranks[right]++;
            }
            
            return true;
        }
        
    private:
        vector<int> groups, ranks;
        
        int find(int id) {
            if (groups[id] == id) {
                return id;
            }
            return groups[id] = find(groups[id]);
        }
    };
    
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        int res = 0;
        vector<vector<int>> edges;
        UnionFind uf(n);
        
        for (int i = 0; i < wells.size(); i++) {
            edges.push_back({wells[i], 0, i + 1});
        }
        
        for (auto& i: pipes) {
            edges.push_back({i[2], i[0], i[1]});
        }
        
        sort(edges.begin(), edges.end());
        
        for (auto& e: edges) {
            if (uf.connect(e[1], e[2])) {
                res += e[0];
            }
        }
        
        return res;
    }
};