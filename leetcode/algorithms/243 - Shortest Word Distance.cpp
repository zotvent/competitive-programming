class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        const int n = words.size();
        int prev1 = -n, prev2 = -n;
        
        for (int i = 0; i < n; i++) {
            if (words[i] == word1) {
                res = min(res, i - prev2);
                prev1 = i;
            }
            else if (words[i] == word2) {
                res = min(res, i - prev1);
                prev2 = i;
            }
        }
        
        return res;
    }
};