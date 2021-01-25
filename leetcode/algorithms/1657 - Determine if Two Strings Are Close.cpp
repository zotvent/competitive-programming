class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        
        const int n = 26;
        vector<int> f1(n, 0), f2(n, 0); // frequency
        
        for (int i = 0; i < word1.size(); i++) {
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }
        
        for (int i = 0; i < n; i++) {
            if ((f1[i] == 0 && f2[i] > 0) || (f1[i] > 0 && f2[i] == 0)) {
                return false;
            }
        }
        
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        
        return f1 == f2;
    }
};