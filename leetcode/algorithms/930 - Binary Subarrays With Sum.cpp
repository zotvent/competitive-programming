class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res = 0;
        
        unordered_map<int, int> m;
        int sum = 0;
        
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            
            if (sum == S) {
                res++;
            }
            
            res += m[sum - S];
                
            m[sum]++;
        }
        
        return res;
    }
};