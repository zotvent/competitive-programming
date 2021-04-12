class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        const int n = 1001;
        vector<int> cnt(n, 0);
        
        for (auto& i: A) {
            cnt[i]++;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (cnt[i] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};