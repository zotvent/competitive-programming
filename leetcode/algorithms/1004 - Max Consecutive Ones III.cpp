class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0;

        for (int i = 0; i < A.size(); i++) {
            int cnt = 0;
            int k = K;

            if (A[i] > 0) cnt = 1;
            else if (k > 0) {
                cnt++;
                k--;
            }
            else continue;

            for (int j = i + 1; j < A.size(); j++) {
                if (A[j] > 0) {
                    cnt++;
                }
                else if (k > 0) {
                    k--;
                    cnt++;
                }
                else break;
            }

            res = max(res, cnt);
        }

        return res;
    }
};