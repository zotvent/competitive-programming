class Solution {
    
    struct UnionFind {
        
        UnionFind(vector<int>& arr) {
            const int n = arr.size();
            size.assign(n, 1);
            par.resize(n);
            
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }
        
        int parent(int id) {
            return (par[id] == id ? par[id] : par[id] = parent(par[id]));
        }
        
        void connect(int l, int r) {
            int left = parent(l);
            int right = parent(r);
            
            if (left == right) {
                return;
            }
            else if (size[left] > size[right]) {
                par[right] = left;
                size[left] += size[right];
            }
            else {
                par[left] = right;
                size[right] += size[left];
            }
        }
        
        bool contains(int id, int value) {
            return freq[parent(id)][value] > 0;
        }
        
        void updateFreq(int id, int value) {
            freq[parent(id)][value]--;
        }
        
        void calcFrequencies(vector<int>& arr) {
            int p;
            for (int i = 0; i < arr.size(); i++) {
                p = parent(i);
                freq[p][arr[i]]++;
            }
        }
        
    private:
        vector<int> par, size;
        unordered_map<int, unordered_map<int, int>> freq;
    };
    
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int res = 0;
        UnionFind uf(source);
        
        for (auto& i: allowedSwaps) {
            uf.connect(i[0], i[1]);
        }
        
        uf.calcFrequencies(source);
        
        for (int i = 0; i < source.size(); i++) {
            if (uf.contains(i, target[i]) > 0) {
                uf.updateFreq(i, target[i]);
            }
            else res++;
        }
        
        return res;
    }
};