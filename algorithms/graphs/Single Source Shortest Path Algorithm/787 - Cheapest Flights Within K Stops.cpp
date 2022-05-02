class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int K) {
        vector<vector<int>> dp(n, vector<int>(K + 5, INT_MAX));

        dp[src][0] = 0;

        int from, to, cost;

        for (int i = 0; i <= K; i++) {
            for (int j = 0; j < flights.size(); j++) {
                from = flights[j][0];
                to = flights[j][1];
                cost = flights[j][2];

                for (int o = 0; o <= K; o++) {
                    if (dp[from][o] < INT_MAX) {
                        if (dp[to][o + 1] > dp[from][o] + cost) {
                            dp[to][o + 1] = dp[from][o] + cost;
                        }
                    }
                }
            }
        }

        int res = INT_MAX;

        for (int i = 0; i <= K + 1; i++) {
            res = min(res, dp[dst][i]);
        }

        return (res == INT_MAX ? -1 : res);
    }
};