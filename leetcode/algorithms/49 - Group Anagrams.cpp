class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> m;
        string key;
        
        for (int i = 0; i < strs.size(); i++) {
            key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }
        
        for (auto i = m.begin(); i != m.end(); i++) {
            res.push_back(i->second);
        }
        
        return res;
    }
};