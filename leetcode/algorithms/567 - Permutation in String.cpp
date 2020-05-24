class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        
        bool res = false;
        
        int n = s1.size();
        int k = s2.size();
        
        vector<int> m(26, 0);
        vector<int> window(26, 0);
        
        for (int i = 0; i < n; i++) {
            m[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }
        
        int head = n;
        int key;
        
        while (head < k && m != window) {
            window[s2[head - n] - 'a']--;
            
            key = s2[head++] - 'a';
            window[key]++;
        }
        
        return m == window;
    }
};