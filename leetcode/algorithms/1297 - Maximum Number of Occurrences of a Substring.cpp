class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> dp;
        unordered_map<char, int> m;
        string cur;
        int j;
        
        for (int i = 0; i < s.size() - minSize + 1; i++) {
            cur.clear();
            m.clear();
            
            for (j = 0; j < minSize - 1; j++) {
                m[s[i + j]]++;
                cur.push_back(s[i + j]);
            }
            
            while (i + j < s.size() && j < maxSize && m.size() <= maxLetters) {
                m[s[i + j]]++;
                cur.push_back(s[i + j]);
                
                if (m.size() <= maxLetters) {
                    dp[cur]++;
                }
                
                j++;
            }
        }
        
        int res = 0;
        
        for (auto it = dp.begin(); it != dp.end(); it++) {
            res = max(res, it->second);
        }
        
        return res;
    }
};