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
        
        void connect(int l, int r) {
            int left = parent(l);
            int right = parent(r);
            
            if (left == right) {
                return;
            }
            
            if (sizes[left] > sizes[right]) {
                parents[right] = left;
                sizes[left] += sizes[right];
            }
            else {
                parents[left] = right;
                sizes[right] += sizes[left];
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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind uf(n);
        sort(logs.begin(), logs.end());
        
        for (auto& i: logs) {
            uf.connect(i[1], i[2]);
            if (uf.getGroups() == 1) {
                return i[0];
            }
        }
        
        return -1;
    }
};