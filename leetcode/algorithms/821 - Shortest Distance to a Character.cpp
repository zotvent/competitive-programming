class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        const int n = s.size();
        vector<int> res(n, INT_MAX);
        int last = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                last = i;
            }
            res[i] = min(res[i], abs(i - last));
        }
        
        last = INT_MAX;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                last = i;
            }
            res[i] = min(res[i], abs(i - last));
        }
        
        return res;
    }
};