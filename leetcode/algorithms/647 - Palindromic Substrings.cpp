class Solution {
    
    void calc(int& res, int l, int r, string& s) {
        const int n = s.size();
        
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
            res++;
        }
    }
    
public:
    int countSubstrings(string s) {
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            calc(res, i, i, s);
            calc(res, i, i + 1, s);
        }
        
        return res;
    }
};