class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        
        int l = 0;
        int r = 0;
        
        for (auto c: s) {
            if (c == 'L') l++;
            else r++;
            
            if (l == r) {
                l = r = 0;
                res++;
            }
        }
        
        return res;
    }
};