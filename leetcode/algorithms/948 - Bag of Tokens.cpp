class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int res = 0, score = 0;
        int lo = 0, hi = tokens.size() - 1;
        
        sort(tokens.begin(), tokens.end());
        
        while (lo <= hi && (P >= tokens[lo] || score > 0)) {
            while (lo <= hi && P >= tokens[lo]) {
                P -= tokens[lo++];
                score++;
            }
            
            res = max(res, score);
            
            if (lo <= hi && score > 0) {
                P += tokens[hi--];
                score--;
            }
        }
        
        return res;
    }
};