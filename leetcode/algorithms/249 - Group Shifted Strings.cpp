class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> m;
        string key;
        
        for (auto& s: strings) {
            key = generateKey(s);
            m[key].push_back(s);
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
    
    string generateKey(string& s) {
        string res = "";

        char head;
        int next;
        
        for (int i = 0; i < s.size(); i++) {
            res.push_back('#');
            
            if (i == 0) {
                next = 0;
                head = s[i];
            }
            else if (s[i] >= head) {
                next = s[i] - head;
            }
            else {
                next = (s[i] - head + 26) % 26;
            }
            
            res += to_string(next);
        }
        
        return res;
    }
};