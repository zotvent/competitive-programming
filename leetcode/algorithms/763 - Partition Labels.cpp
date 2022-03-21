class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res, m(26, -1);
        const int n = s.size();
        int last = 0, start = 0;
        
        for (int i = 0; i < n; i++) {
            m[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < n; i++) {
            last = max(last, m[s[i] - 'a']);
            if (i == last) {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        
        return res;
    }
};