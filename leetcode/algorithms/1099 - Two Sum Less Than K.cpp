class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int res = -1;
        
        sort(A.begin(), A.end());
        int left = 0, right = A.size() - 1;
        int sum;
        
        while (left < right) {
            sum = A[left] + A[right];
            
            if (sum >= K) right--;
            else {
                res = max(res, sum);
                left++;
            }
        }
        
        return res;
    }
};