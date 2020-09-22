class Solution {
    
    vector<int> parse(string& s) {
        vector<int> res;
        
        string cur = "";
        const int n = s.size();
        
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == '.') {
                res.push_back(stoi(cur));
                cur.clear();
            }
            else {
                cur.push_back(s[i]);
            }
        }
        
        return res;
    }
    
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = parse(version1);
        vector<int> v2 = parse(version2);
        int dif = abs((int) v2.size() - (int) v1.size());
        
        for (int i = 0; i < dif; i++) {
            if (v1.size() < v2.size()) {
                v1.push_back(0);
            }
            else {
                v2.push_back(0);
            }
        }
        
        const int n = v1.size();
        
        for (int i = 0; i < n; i++) {
            if (v1[i] < v2[i]) {
                return -1;
            }
            else if (v1[i] > v2[i]) {
                return 1;
            }
        }
        
        return 0;
    }
};