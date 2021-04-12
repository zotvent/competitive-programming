class Solution {
    
    struct DisjointSetUnion {
        
        DisjointSetUnion(int size) {
            parent.resize(size);
            rank.assign(size, 0);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }
        
        bool connect(int l, int r) {
            int left = root(l);
            int right = root(r);
            
            if (left == right) {
                return false;
            }
            else if (rank[left] > rank[right]) {
                parent[right] = left;
            }
            else if (rank[left] < rank[right]) {
                parent[left] = right;
            }
            else {
                parent[left] = right;
                rank[right]++;
            }
            
            return true;
        }
        
    private:
        vector<int> parent, rank;
        
        int root(int id) {
            if (parent[id] != id) parent[id] = root(parent[id]);
            return parent[id];
        }
    };
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSetUnion dsu(1001);
        vector<int> res;
        
        for (auto& e: edges) {
            if (!dsu.connect(e[0], e[1])) {
                res = e;
            }
        }
        
        return res;
    }
};