class Solution {
    
    struct DisjointSetUnion {
        
        DisjointSetUnion(int maxValue) {
            parent.resize(maxValue + 1);
            size.resize(maxValue + 1);
            for (int i = 0; i < maxValue + 1; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                return find(parent[x]);
            }
            return parent[x];
        }
        
        int makeUnion(int x, int y) {
            int px = find(x);
            int py = find(y);
            
            if (px == py) {
                return px;
            }
            
            if (size[px] > size[py]) {
                swap(px, py);
            }
            
            parent[px] = py;
            size[py] += size[px];
            return py;
        }
        
        private:
            vector<int> parent, size;
    };
    
    vector<int> primeDecompose(int x) {
        vector<int> res;
        int factor = 2;
        
        while (x >= factor * factor) {
            if (x % factor == 0) {
                res.push_back(factor);
                x /= factor;
            }
            else {
                factor++;
            }
        }
        
        res.push_back(x);
        
        return res;
    }
    
public:
    int largestComponentSize(vector<int>& A) {
        int maxValue = 1;
        
        for (auto& i: A) {
            maxValue = max(maxValue, i);
        }
        
        DisjointSetUnion dsu(maxValue);
        unordered_map<int, int> numFactorMap;
        
        vector<int> primeFactors;
        set<int> uniquePrimeFactors;
        
        for (auto& i: A) {
            primeFactors = primeDecompose(i);
            uniquePrimeFactors = set<int>(primeFactors.begin(), primeFactors.end());
            primeFactors = vector<int>(uniquePrimeFactors.begin(), uniquePrimeFactors.end());

            numFactorMap[i] = primeFactors[0];
            
            for (int i = 0; i < primeFactors.size() - 1; i++) {
                dsu.makeUnion(primeFactors[i], primeFactors[i + 1]);
            }
        }
        
        int res = 0;
        
        unordered_map<int, int> groupCount;
        int groupId;
        
        for (auto& i: A) {
            groupId = dsu.find(numFactorMap[i]);
            groupCount[groupId]++;
            res = max(res, groupCount[groupId]);
        }
        
        return res;
    }
};