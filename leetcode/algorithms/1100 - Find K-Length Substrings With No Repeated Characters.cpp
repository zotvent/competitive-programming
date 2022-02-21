class Solution {
    
    char toInt(char c) {
        return c - 'a';
    }
    
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int res = 0, start = -1;
        vector<int> m(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            if (m[toInt(s[i])] != -1) {
                start = max(start, m[toInt(s[i])]);
            }
            m[toInt(s[i])] = i;
            
            if (i - start == k) {
                res++;
                start++;
            }
        }
        
        return res;
    }
};