class Solution {
    
    int toInt(char c) {
        return c - 'a';
    }
    
public:
    int maxNumberOfBalloons(string text) {
        int res = INT_MAX;
        const string p = "balloon";
        vector<int> t(26, 0), pattern(26, 0);
        
        for (auto& i: text) {
            t[toInt(i)]++;
        }
        for (auto& i: p) {
            pattern[toInt(i)]++;
        }
        
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] > 0) {
                res = min(res, t[i] / pattern[i]);
            }
        }
        
        return res;
    }
};