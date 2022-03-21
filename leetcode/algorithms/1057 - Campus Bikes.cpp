class Solution {
    
    int distance(vector<int>& l, vector<int>& r) {
        return abs(l[0] - r[0]) + abs(l[1] - r[1]);
    }
    
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        const int n = workers.size();
        const int m = bikes.size();
        vector<int> res(n, -1), used(m, 0);
        vector<vector<vector<int>>> buckets(2000);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int d = distance(workers[i], bikes[j]);
                buckets[d].push_back({i, j});
            }
        }
        
        for (auto& bucket: buckets) {
            for (auto& i: bucket) {
                int w = i[0], b = i[1];
                if (res[w] == -1 && !used[b]) {
                    res[w] = b;
                    used[b] = 1;
                }
            }
        }
        
        return res;
    }
};