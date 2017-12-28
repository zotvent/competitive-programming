class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int cur = 0;
        for (int i = S.length()-1; i >= 0; i--) {
            if (S[i] != '-') {
                if (cur == K) {
                    res.push_back('-');
                    cur = 0;
                }
                
                char c = (isalpha(S[i]) ? toupper(S[i]) : S[i]);
                res.push_back(c);
                cur++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};