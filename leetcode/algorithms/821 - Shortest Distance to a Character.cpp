class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.size(), 10000);
        int cur = -1;

        // forward
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                res[i] = 0;
                cur = i;
            }
            else if (cur != -1) {
                res[i] = min(res[i], abs(i - cur));
            }
        }
        // reverse
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == C) {
                cur = i;
            }
            res[i] = min(res[i], abs(i - cur));
        }

        return res;
    }
};