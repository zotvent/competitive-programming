class Solution {
    
    struct UnionFind {
        
        UnionFind(int n) {
            par.resize(n);
            size.assign(n, 1);
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }
        
        bool connect(int l, int r) {
            int left = parent(l);
            int right = parent(r);
            
            if (left == right) {
                return false;
            }
            else if (size[left] > size[right]) {
                par[right] = left;
                size[left] += size[right];
            }
            else {
                par[left] = right;
                size[right] += size[left];
            }
            
            return true;
        }
        
        int parent(int id) {
            return par[id] == id ? id : par[id] = parent(par[id]);
        }
        
    private:
        vector<int> par, size;
    };
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        
        UnionFind uf(n);
        int groups = n;
        
        for (auto& i: connections) {
            if (uf.connect(i[0], i[1])) {
                groups--;
            }
        }
        
        return groups - 1;
    }
};