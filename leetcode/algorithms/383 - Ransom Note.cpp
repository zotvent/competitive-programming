class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        
        for (auto& i: magazine) freq[i - 'a']++;
        for (auto& i: ransomNote) freq[i - 'a']--;
        for (auto& i: freq) {
            if (i < 0) return false;
        }
        
        return true;
    }
};