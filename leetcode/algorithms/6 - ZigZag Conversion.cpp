class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        
        vector<string> v(numRows, "");
        int i = 0;
        
        while (i < s.size()) {
            // down
            for (int j = 0; j < numRows && i < s.size(); j++) {
                v[j].push_back(s[i++]);
            }
            // up
            for (int j = numRows - 2; j > 0 && i < s.size(); j--) {
                v[j].push_back(s[i++]);
            }
        }
        
        for (auto i: v) {
            res += i;
        }
        
        return res;
    }
};