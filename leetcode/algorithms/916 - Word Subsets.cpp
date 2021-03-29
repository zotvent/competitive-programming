class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> res;
        const int n = 26;
        vector<int> m(n, 0), cur(n, 0);
        bool valid;
        
        for (auto& b: B) {
            cur.assign(n, 0);
            
            for (auto& i: b) {
                cur[i - 'a']++;
            }
            
            for (int i = 0; i < n; i++) {
                m[i] = max(m[i], cur[i]);
            }
        }
        
        for (auto& a: A) {
            cur.assign(n, 0);
            valid = true;
            
            for (auto& i: a) {
                cur[i - 'a']++;
            }
            
            for (int i = 0; i < n; i++) {
                if (cur[i] < m[i]) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                res.push_back(a);
            }
        }
        
        return res;
    }
};