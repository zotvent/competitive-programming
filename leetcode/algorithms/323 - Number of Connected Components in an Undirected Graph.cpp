class Solution {
    
    struct UnionFind {
        
        UnionFind(int n) {
            cnt.assign(n, 1);
            p.resize(n);
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }
        
        bool connect(int l, int r) {
            int left = parent(l);
            int right = parent(r);
            
            if (left == right) {
                return false;
            }
            else if (cnt[left] > cnt[right]) {
                cnt[left] += cnt[right];
                p[right] = left;
            }
            else {
                cnt[right] += cnt[left];
                p[left] = right;
            }
            
            return true;
        }
        
    private:
        vector<int> p, cnt;
        
        int parent(int id) {
            if (p[id] != id) {
                p[id] = parent(p[id]);
            }
            return p[id];
        }
    };
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;
        UnionFind uf(n);
        
        for (auto& e: edges) {
            if (uf.connect(e[0], e[1])) {
                res--;
            }
        }
        
        return res;
    }
};