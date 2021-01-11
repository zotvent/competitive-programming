class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        
        int res = 0;
        int start = 0;
        unordered_map<char, int> last;
        char mn;
        
        for (int i = 0; i < s.size(); i++) {
            if (last.count(s[i]) == 0 && last.size() == k) {
                mn = (last.begin())->first;
                
                for (auto it = last.begin(); it != last.end(); it++) {
                    if (last[mn] > it->second) {
                        mn = it->first;
                    }
                }
                
                start = last[mn] + 1;
                last.erase(mn);
            }
            
            last[s[i]] = i;
            res = max(res, i - start + 1);
        }
        
        res = max(res, (int) s.size() - start);
        
        return res;
    }
};