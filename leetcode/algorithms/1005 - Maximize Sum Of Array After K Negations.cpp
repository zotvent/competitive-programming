class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int sum = 0;
        
        vector<int> v = A;
        sort(v.begin(), v.end());
        
        int neg = 0;
        bool hasZero = false;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < 0) {
                neg++;
            }
            else if (v[i] == 0) {
                hasZero = true;
            }
        }

        bool lessNegative = neg < K;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] < 0 && K > 0) {
                v[i] = -v[i];
                K--;
            }
        }

        if (lessNegative && K % 2 == 1 && !hasZero) {
            sort(v.begin(), v.end());
            v[0] = -v[0];
        }

        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }
        
        return sum;
    }
};