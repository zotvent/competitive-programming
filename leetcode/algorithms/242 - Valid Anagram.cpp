class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(128, 0);
        
        for (auto& c: s) freq[c]++;
        for (auto& c: t) freq[c]--;
        
        for (auto& i: freq) {
            if (i != 0) {
                return false;
            }
        }
        
        return true;
    }
};