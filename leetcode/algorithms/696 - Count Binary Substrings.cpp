class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v;
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1])
                count++;
            else {
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);
        
        int res = 0;
        for (int i = 1; i < v.size(); i++)
            res += min(v[i], v[i-1]);
        return res;
    }
};