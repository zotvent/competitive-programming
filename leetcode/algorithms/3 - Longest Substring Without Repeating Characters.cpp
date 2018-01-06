class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, start = -1;
        vector<int> d(128, -1);
        for (int i = 0; i < s.length(); i++) {
            if (d[s[i]] > start) 
                start = d[s[i]];
            d[s[i]] = i;
            res = max(res, d[s[i]]-start);
        }
        return res;
    }
};