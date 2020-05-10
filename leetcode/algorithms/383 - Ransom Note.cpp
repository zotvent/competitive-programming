class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26, 0), m(26, 0);
        
        for (auto i: ransomNote) {
            r[i - 'a']++;
        }
        
        for (auto i: magazine) {
            m[i - 'a']++;
        }
        
        for (int i = 0; i < r.size(); i++) {
            if (r[i] > m[i]) {
                return false;
            }
        }
        
        return true;
    }
};