class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum = INT_MIN, curMax = 0;
        int minSum = INT_MAX, curMin = 0;
        int sum = 0;
        
        for (auto i: A) {
            curMax = max(curMax + i, i);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + i, i);
            minSum = min(minSum, curMin);
            sum += i;
        }
        
        return (maxSum > 0 ? max(maxSum, sum - minSum) : maxSum);
    }
};