class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = words.size();
        vector<vector<int>> indices(26);
        int key, index;
        
        for (int i = 0; i < s.size(); i++) {
            key = s[i] - 'a';
            indices[key].push_back(i);
        }
        
        for (auto& word: words) {
            index = -1;
            for (auto& c: word) {
                key = c - 'a';
                auto it = upper_bound(indices[key].begin(), indices[key].end(), index);
                if (it == indices[key].end()) {
                    res--;
                    break;
                }
                index = *it;
            }
        }
        
        return res;
    }
};