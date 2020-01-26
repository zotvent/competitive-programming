class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res;
        
        map<int, int> m;
        for (auto i: arr) {
            m[i] = 1;
        }
        
        int k = 1;
        for (auto it = m.begin(); it != m.end(); it++) {
            it->second = k;
            k++;
        }
        
        for (auto i: arr) {
            res.push_back(m[i]);
        }
        
        return res;
    }
};