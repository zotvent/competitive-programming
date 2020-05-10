class Solution {
public:
    int maxDiff(int num) {        
        int small = 9;
        pair<int, int> big = {0, 0}; // from, to
        
        string s = to_string(num);
        
        for (auto i: s) {
            if (i < '9') {
                small = i - '0';
                break;
            }
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 && s[i] > '1') {
                big = {s[i] - '0', 1};
                break;
            }
            else if (i > 0 && s[i] > '0' && s[0] != s[i]) {
                big = {s[i] - '0', 0};
                break;
            }
        }
        
        int res = replace(s, small, 9) - replace(s, big.first, big.second);
                
        return res;
    }
    
    int replace(string s, int from, int to) {
        int res = 0;
        int cur;
        
        for (auto i: s) {
            cur = i - '0';
            
            if (cur == from) {
                res = res * 10 + to;
            }
            else {
                res = res * 10 + cur;
            }
        }
        
        return res;
    }
};