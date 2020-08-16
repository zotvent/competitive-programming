class Solution {
    
    int toBase26(char c) {
        return c - 'A' + 1;
    }
    
public:
    int titleToNumber(string s) {
        int res = 0;
        
        for (auto& c: s) {
            res = res * 26 + toBase26(c);
        }
        
        return res;
    }
};