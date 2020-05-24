class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        
        unordered_map<char, int> m;
        
        for (auto& c: s) {
            m[c]++;
        }
        
        vector<pair<int, char>> freq;
        
        for (auto it = m.begin(); it != m.end(); it++) {
            freq.push_back({it->second, it->first});
        }
        
        sort(freq.begin(), freq.end());
        
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int j = 0; j < freq[i].first; j++) {
                res.push_back(freq[i].second);
            }
        }
        
        return res;
    }
};