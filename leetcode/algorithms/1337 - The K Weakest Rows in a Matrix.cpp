class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        
        set<pair<int, int>> s;
        int cnt;
        
        for (int i = 0; i < mat.size(); i++) {
            cnt = 0;
            
            for (int j = 0; j < mat[i].size(); j++) {
                cnt += mat[i][j];
            }
            
            s.insert({cnt, i});
        }
        
        for (auto it = s.begin(); k > 0; it++, k--) {
            res.push_back(it->second);
        }
        
        return res;
    }
};