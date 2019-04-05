class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int cur = 0;
        
        for (auto i: A) {
            cur = (cur * 2 + i) % 5;
            res.push_back(!cur);
        }
        
        return res;
    }
};