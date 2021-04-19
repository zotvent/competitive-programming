class Solution {
    
    struct UnionFind {
        
        UnionFind(int n) {
            ds.assign(n, -1);
        }
        
        int parent(int id) {
            return ds[id] == -1 ? id : ds[id] = parent(ds[id]);
        }
        
        bool connect(int l, int r) {
            int left = parent(l);
            int right = parent(r);
            
            if (left == right) {
                return false;
            }
            
            ds[min(left, right)] = max(left, right);
            return true;
        }
        
    private:
        vector<int> ds;
    };
    
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        int res = 0, edges = 0;
        UnionFind uf(N + 1);
        
        sort(connections.begin(), connections.end(), [](const vector<int>& l, const vector<int>& r) {
            return l[2] < r[2];
        });
        
        for (auto& i: connections) {
            if (uf.connect(i[0], i[1])) {
                res += i[2];
                edges++;
            }
        }
        
        return edges == N - 1 ? res : -1;
    }
};