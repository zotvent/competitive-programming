class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res = "";
        vector<pair<char, int>> v;
        
        for (auto& i: s) {
            if (v.empty() || v.back().first != i) {
                v.push_back({i, 1});
            }
            else if (v.back().second + 1 == k) {
                v.pop_back();
            }
            else {
                v.back().second++;
            }
        }
        
        for (auto& i: v) {
            for (int j = 0; j < i.second; j++) {
                res.push_back(i.first);
            }
        }
        
        return res;
    }
};