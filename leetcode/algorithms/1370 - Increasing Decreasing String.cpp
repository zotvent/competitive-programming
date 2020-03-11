class Solution {
public:
    string sortString(string s) {
        string res = "";
        
        vector<int> a(26, 0);
        int cnt = (int) s.size();
        
        for (int i = 0; i < s.size(); i++) {
            a[s[i] - 'a']++;
        }
        
        while (cnt > 0) {
            for (int i = 0; i < 26; i++) {
                if (a[i] > 0) {
                    res.push_back(i + 'a');
                    a[i]--;
                    cnt--;
                }
            }
            
            for (int i = 25; i >= 0; i--) {
                if (a[i] > 0) {
                    res.push_back(i + 'a');
                    a[i]--;
                    cnt--;
                }
            }
        }
        
        return res;
    }
};