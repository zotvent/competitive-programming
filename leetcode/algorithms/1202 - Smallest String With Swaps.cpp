class Solution {
    
    struct UnionFind {
        UnionFind(int n) {
            sizes.assign(n, 1);
            parents.resize(n);
            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
        }
        
        void connect(int l, int r) {
            int left = parent(l);
            int right = parent(r);
            
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
        }
        
        int parent(int id) {
            if (parents[id] == id) {
                return id;
            }
            return parents[id] = parent(parents[id]);
        }
        
    private:
        vector<int> parents, sizes;
    };
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int n = s.size();
        UnionFind uf(n);
        string res = s;
        
        for (auto& i: pairs) {
            uf.connect(i[0], i[1]);
        }
        
        vector<int> parents(n);
        
        for (int i = 0; i < n; i++) {
            parents[i] = uf.parent(i);
        }
        
        unordered_map<int, vector<int>> indexByParent;
        unordered_map<int, vector<int>> charByParent;
        
        for (int i = 0; i < n; i++) {
            int key = parents[i];
            indexByParent[key].push_back(i);
            if (charByParent.count(key) == 0) {
                charByParent[key].assign(26, 0);
            }
            charByParent[key][s[i] - 'a']++;
        }
        
        for (auto& i: charByParent) {
            int key = i.first, head = 0;
            
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < i.second[j]; k++) {
                    res[indexByParent[key][head++]] = j + 'a';
                }
            }
        }
        
        return res;
    }
};