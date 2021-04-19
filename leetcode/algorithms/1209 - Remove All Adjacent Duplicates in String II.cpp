class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> last;
        
        for (auto& c: s) {
            if (!last.empty() && last.back().first == c) {
                last.back().second++;
            }
            else {
                last.push_back({c, 1});
            }
            
            while (!last.empty() && last.back().second == k) {
                last.pop_back();
            }
        }
        
        string res = "";
        
        for (auto& i: last) {
            for (int j = 0; j < i.second; j++) {
                res.push_back(i.first);
            }
        }
        
        return res;
    }
};