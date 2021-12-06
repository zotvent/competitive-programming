class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        
        for (auto& i: nums) {
            sum = max(sum + i, i);
            res = max(res, sum);
        }
        
        return res;
    }
};