class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> m;
        vector<int> cnt;
        string key;
        
        for (auto& i: strs) {
            cnt.assign(26, 0);
            for (auto& c: i) {
                cnt[c - 'a']++;
            }
            key = generateKey(cnt);
            m[key].push_back(i);
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
    
    string generateKey(vector<int>& cnt) {
        string res = "";
        
        for (auto& i: cnt) {
            res.push_back('#');
            res += to_string(i);
        }
        
        return res;
    }
};