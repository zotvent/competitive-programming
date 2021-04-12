class Solution {
    
    struct UnionFind {
        
        UnionFind(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        void connect(int l, int r) {
            parent[root(l)] = root(r);
        }
        
        int root(int id) {
            if (parent[id] != id) {
                parent[id] = root(parent[id]);
            }
            return parent[id];
        }
        
    private:
        vector<int> parent;
    };
    
public:
    int regionsBySlashes(vector<string>& grid) {
        const int n = grid.size();
        UnionFind uf(4 * n * n);
        int id;
        char symbol;
        
        //each cell is divided in 4 pieces with indexes
        // 0
        //3 1
        // 2
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                id = 4 * (r * n + c);
                symbol = grid[r][c];
                
                if (symbol != '\\') {
                    uf.connect(id + 0, id + 3);
                    uf.connect(id + 1, id + 2);
                }
                if (symbol != '/') {
                    uf.connect(id + 0, id + 1);
                    uf.connect(id + 2, id + 3);
                }
                
                //north
                if (r > 0) uf.connect(id + 0, (id - 4 * n) + 2);
                //west
                if (c > 0) uf.connect(id + 3, (id - 4) + 1);
            }
        }
        
        int res = 0;
        
        for (int i = 0; i < 4 * n * n; i++) {
            if (uf.root(i) == i) {
                res++;
            }
        }
        
        return res;
    }
};