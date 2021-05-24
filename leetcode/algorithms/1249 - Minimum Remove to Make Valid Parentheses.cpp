class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        vector<int> open, close;
        int l = 0, r = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open.push_back(i);
            else if (s[i] == ')') {
                if (!open.empty()) open.pop_back();
                else close.push_back(i);
            }
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (l < open.size() && open[l] == i) {
                l++;
            }
            else if (r < close.size() && close[r] == i) {
                r++;
            }
            else res.push_back(s[i]);
        }
        
        return res;
    }
};