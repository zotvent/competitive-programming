class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int res = INT_MAX;
        
        int n = (int) S.size();
        vector<int> zero(n, 0);
        vector<int> one(n, 0);
        
        for (int i = 0; i < n; i++) {
            zero[i] = (S[i] == '0') + (i > 0 ? zero[i - 1] : 0);
            one[i] = (S[i] == '1') + (i > 0 ? one[i - 1] : 0);
        }
        
        int tmp;
        for (int i = 0; i < n; i++) {
            tmp = (i > 0 ? one[i - 1] : 0) + zero[n - 1] - zero[i]; 
            res = min(res, tmp);
        }
        
        return res;
    }
};