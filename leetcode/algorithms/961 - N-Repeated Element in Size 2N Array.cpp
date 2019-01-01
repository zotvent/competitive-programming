class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        vector<int> cnt(1e4 + 5, 0);
        int i;
        
        for (i = 0; i < A.size(); i++) {
            cnt[A[i]]++;
            if (cnt[A[i]] > 1) break;
        }
        
        return A[i];
    }
};