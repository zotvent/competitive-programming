class Solution {
    
    struct UnionFind {
        
        UnionFind(int n) {
            sizes.assign(n, 1);
            parents.resize(n);
            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
            groups = n;
        }
        
        bool isConnected(int l, int r) {
            return parent(l) == parent(r);
        }
        
        void connect(int l, int r) {
            int left = parent(l), right = parent(r);
            
            if (left == right) {
                return;
            }
            
            if (sizes[left] > sizes[right]) {
                sizes[left] += sizes[right];
                parents[right] = left;
            }
            else {
                sizes[right] += sizes[left];
                parents[left] = right;
            }
            groups--;
        }
        
        int getGroups() {
            return groups;
        }
        
    private:
        vector<int> parents, sizes;
        int groups;
        
        int parent(int id) {
            if (parents[id] == id) {
                return id;
            }
            return parents[id] = parent(parents[id]);
        }
    };
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf = UnionFind(n);
        
        for (auto& e: edges) {
            if (uf.isConnected(e[0], e[1])) {
                return false;
            }
            uf.connect(e[0], e[1]);
        }
        
        return uf.getGroups() == 1;
    }
};