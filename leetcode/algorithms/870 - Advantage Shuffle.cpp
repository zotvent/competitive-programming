class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> res, a = A, b = B;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        unordered_map<int, vector<int>> m;
        vector<int> remaining;
        int j = 0;
        
        for (auto& i: a) {
            if (i > b[j]) m[b[j++]].push_back(i);
            else remaining.push_back(i);
        }
        
        for (auto& i: B) {
            if (m[i].empty()) {
                res.push_back(remaining.back());
                remaining.pop_back();
            }
            else {
                res.push_back(m[i].back());
                m[i].pop_back();
            }
        }
        
        return res;
    }
};