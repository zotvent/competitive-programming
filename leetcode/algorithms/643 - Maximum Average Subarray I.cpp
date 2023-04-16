class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0;
        for (int i = 0; i < k; i++) {
            res += nums[i];
        }
        double sum = res;
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];
            res = max(res, sum);
        }
        return res / k;
    }
};
