class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        vector<pair<int, int>> v;
        
        for (auto i: arr) {
            v.push_back({count_ones(i), i});
        }
        
        sort(v.begin(), v.end());
        
        for (auto i: v) {
            res.push_back(i.second);
        }
        
        return res;
    }
    
    int count_ones(int x) {
        int res = 0;
        
        while (x > 0) {
            res += x & 1;
            x >>= 1;
        }
        
        return res;
    }
};