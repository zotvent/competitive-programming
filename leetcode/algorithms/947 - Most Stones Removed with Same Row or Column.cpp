class Solution {
    
    struct UnionFind {
        
        UnionFind(int n) {
            par.resize(n);
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }
        
        int parent(int id) {
            if (par[id] != id) {
                par[id] = parent(par[id]);
            }
            return par[id];
        }
        
        void connect(int l, int r) {
            par[parent(l)] = parent(r);
        }
        
    private:
        vector<int> par;
    };
    
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        UnionFind uf(2e4 + 1);
        int shift = 1e4;
        unordered_set<int> seen;
        
        for (auto& s: stones) {
            uf.connect(s[0], s[1] + shift);
        }
        
        for (auto& s: stones) {
            seen.insert(uf.parent(s[0]));
        }
        
        return n - seen.size();
    }
};