class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int max_size = 0;

        vector<vector<int>> dp = mat;

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                dp[i][j] += dp[i][j - 1];
            }
        }

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] += dp[i - 1][j];
            }
        }

        // solution

        int left_rows;
        int left_cols;
        int a;
        int tmp;

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                left_rows = dp.size() - 1 - i;
                left_cols = dp[i].size() - 1 - j;
                a = min(left_rows, left_cols);

                for (int k = 1; k <= a; k++) {
                    tmp = dp[i + k][j + k];

                    if (i) tmp -= dp[i - 1][j + k];
                    if (j) tmp -= dp[i + k][j - 1];
                    if (i && j) tmp += dp[i - 1][j - 1];

                    if (tmp <= threshold) {
                        max_size = max(max_size, k + 1);
                    }
                }
            }
        }

        return max_size;
    }
};