class Solution {
public:
    bool isAnagram(string s, string t) {
        int const k = 128;
        int cnt[k];
        for (int i = 0; i < k; i++) cnt[i] = 0;
        
        for (int i = 0; i < s.length(); i++) cnt[(int) s[i]]++;
        for (int i = 0; i < t.length(); i++) cnt[(int) t[i]]--;
        
        for (int i = 0; i < k; i++)
            if (cnt[i] != 0) return false;
        return true;
    }
};