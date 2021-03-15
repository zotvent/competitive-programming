class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k;
        vector<bool> found(need);
        int mask = need - 1, hash = 0;
        
        for (int i = 0; i < s.size(); i++) {
            hash = ((hash << 1) & mask) | (s[i] - '0');
            if (i >= k - 1 && !found[hash]) {
                found[hash] = true;
                need--;
                if (need == 0) {
                    return true;
                }
            }
        }
        
        return false;
    }
};