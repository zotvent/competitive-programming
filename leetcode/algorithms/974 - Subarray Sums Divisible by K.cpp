class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res = 0;
        
        vector<int> m(K + 1, 0);
        m[0] = 1;
        int sum = 0;
        
        for (int i = 0; i < A.size(); i++) {
            sum = (sum + A[i]) % K;
            if (sum < 0) sum += K;
            res += m[sum];
            m[sum]++;
        }
        
        return res;
    }
};