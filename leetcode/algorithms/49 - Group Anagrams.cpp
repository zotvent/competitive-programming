class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> m;
        string unsorted;
        for (int i = 0; i < strs.size(); i++) {
            unsorted = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(unsorted);
        }
                
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        
        return res;
    }
};