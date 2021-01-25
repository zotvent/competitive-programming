class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        const int base = 26;
        
        while (n > 0) {
            n--;
            res.push_back(n % base + 'A');
            n /= base;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};