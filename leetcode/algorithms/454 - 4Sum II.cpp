class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        
        unordered_map<int, int> m;
        
        for (auto& a: A) {
            for (auto& b: B) {
                m[a + b]++;
            }
        }
        
        for (auto& c: C) {
            for (auto& d: D) {
                if (m.count(0 - c - d) > 0) {
                    res += m[0 - c - d];
                }
            }
        }
        
        return res;
    }
};