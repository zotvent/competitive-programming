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
                int complement = 0 - c - d;
                if (m.count(complement) > 0) {
                    res += m[complement];
                }
            }
        }
        
        return res;
    }
};