class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        
        vector<int> d(2, -1);
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                d[0] = i;
                if (d[1] != -1) {
                    res = min(res, abs(d[0] - d[1]));
                }
            }
            else if (words[i] == word2) {
                d[1] = i;
                if (d[0] != -1) {
                    res = min(res, abs(d[0] - d[1]));
                }
            }
        }
        
        return res;
    }
};