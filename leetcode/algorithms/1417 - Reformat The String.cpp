class Solution {
public:
    string reformat(string s) {
        string res = "";
        
        int letters = 0;
        int digits = 0;
        
        for (auto c: s) {
            if (isdigit(c)) digits++;
            else letters++;
        }
        
        if (abs(digits - letters) < 2) {
            sort(s.begin(), s.end());
            
            int l, d = 0;
            int cnt = 1;
            
            for (int i = 0; i < s.size(); i++) {
                if (isalpha(s[i])) {
                    l = i;
                    break;
                }
            }
            
            vector<int> index = {l, d};
            if (letters > digits) swap(index[0], index[1]);
            
            while (cnt <= s.size()) {
                res.push_back(s[index[cnt % 2]++]);
                cnt++;
            }
        }
        
        return res;
    }
};