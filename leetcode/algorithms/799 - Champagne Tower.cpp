class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        const int n = 100;
        vector<double> state(n), next(n);
        state[0] = poured;
        
        for (int row = 1; row <= query_row; row++) {
            for (int col = 0; col <= row; col++) {
                next[col] = max(state[col] - 1, 0.0) / 2;
                if (col > 0) {
                    next[col] += max(state[col - 1] - 1, 0.0) / 2;
                }
            }
            state = next;
        }
        
        return min(state[query_glass], 1.0);
    }
};