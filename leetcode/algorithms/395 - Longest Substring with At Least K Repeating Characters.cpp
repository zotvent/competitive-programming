class Solution {
    
    int getUniqueCharacters(string s) {
        unordered_set<char> unique;
        
        for (auto& c: s) {
            unique.insert(c);
        }
        
        return unique.size();
    }
    
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int maxUnique = getUniqueCharacters(s);
        int start, end, idx, unique, countAtLeastK;
        vector<int> cnt;
        
        for (int curUnique = 1; curUnique <= maxUnique; curUnique++) {
            start = end = 0;
            idx = 0; 
            unique = countAtLeastK = 0;
            cnt.assign(26, 0);
            
            while (end < s.size()) {
                if (unique <= curUnique) {
                    idx = s[end] - 'a';
                    if (cnt[idx] == 0) unique++;
                    cnt[idx]++;
                    if (cnt[idx] == k) countAtLeastK++;
                    end++;
                }
                else {
                    idx = s[start] - 'a';
                    if (cnt[idx] == k) countAtLeastK--;
                    cnt[idx]--;
                    if (cnt[idx] == 0) unique--;
                    start++;
                }
                
                if (unique == curUnique && unique == countAtLeastK) {
                    res = max(res, end - start);
                }
            }
        }
        
        return res;
    }
};