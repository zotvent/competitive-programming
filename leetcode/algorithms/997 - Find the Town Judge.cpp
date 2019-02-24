class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int res = -1;
        
        vector<int> trusts(N + 1, 0);
        vector<int> trustedBy(N + 1, 0);
        
        for (int i = 0; i < trust.size(); i++) {
            int from = trust[i][0];
            int to = trust[i][1];
            
            trusts[from]++;
            trustedBy[to]++;
        }
        
        for (int i = 1; i <= N; i++) {
            if (trusts[i] == 0 && trustedBy[i] == N - 1) {
                res = i;
            }
        }
        
        return res;
    }
};