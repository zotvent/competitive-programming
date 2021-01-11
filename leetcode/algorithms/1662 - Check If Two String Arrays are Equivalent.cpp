class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        const int n = word1.size();
        const int m = word2.size();
        vector<int> l(2, 0), r(2, 0);
        
        while (l[0] < n && r[0] < m) {
            if (word1[l[0]][l[1]] != word2[r[0]][r[1]]) {
                return false;
            }
            
            l[1]++;
            r[1]++;
            
            if (l[1] == word1[l[0]].size()) {
                l[0]++;
                l[1] = 0;
            }
            
            if (r[1] == word2[r[0]].size()) {
                r[0]++;
                r[1] = 0;
            }
        }
        
        return l[0] == n && r[0] == m;
    }
};